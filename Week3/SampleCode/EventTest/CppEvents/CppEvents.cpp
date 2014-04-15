// CppEvents.cpp
#include "pch.h"
#include "CppEvents.h"
#include <windows.h> // For WaitForSingleObjectEx()

/*

// This searches in your project
#include "myHeader.h"

// This searches in the system include directories
#include <myHeader.h>

*/

using namespace CppEvents;
using namespace Platform;
using namespace Windows::System::Threading;

CppThread::CppThread()
{
	// Initialize variables to null values
	this->counter = 0;
	this->threadHandle = ThreadPool::RunAsync( ref new WorkItemHandler(this, &CppThread::thread) );

	this->onTimerTick += ref new MyEvent(this, &CppThread::doWork);
}

void CppThread::doWork( int not_using_you ) {
	this->counter = this->counter * this->counter;
}

CppThread::~CppThread()
{
	this->threadHandle->Cancel();
}

void CppThread::thread( IAsyncAction^ operation ) {
	// Keep looping as long as the threadHandle doesn't think we've been canceled
	while( this->threadHandle->Status != AsyncStatus::Canceled ) {
		// Increment the counter (from another thread!  Note this isn't thread-safe in general!)
		this->counter++;

		// Call the event
		this->onTimerTick( this->counter );

		// Wait 50ms
		WaitForSingleObjectEx(GetCurrentThread(), 1000, FALSE);
	}

	// Once we've been canceled, clean up the threadHandle resources
	this->threadHandle->Close();
	this->threadHandle = nullptr;
}