// CounterThread.cpp
#include "pch.h"
#include "CounterThread.h"
#include <windows.h>

using namespace CounterThread;
using namespace Platform;
using namespace Windows::System::Threading;

CounterThreadClass::CounterThreadClass()
{
	// Initialize variables to null values
	this->counter = 0;
	this->threadHandle = nullptr;
}

CounterThreadClass::~CounterThreadClass()
{
	this->stop();
}

void CounterThreadClass::start() {
	// Only start a new thread if we don't already have one running
	if( this->threadHandle == nullptr )
		this->threadHandle = ThreadPool::RunAsync( ref new WorkItemHandler(this, &CounterThreadClass::thread) );
}

void CounterThreadClass::stop() {
	// Only stop a thread if we DO have one running
	if( this->threadHandle != nullptr )
		this->threadHandle->Cancel();
}

int CounterThreadClass::getCounter() {
	return this->counter;
}

void CounterThreadClass::thread( IAsyncAction^ operation ) {
	// Keep looping as long as the threadHandle doesn't think we've been canceled
	while( this->threadHandle->Status != AsyncStatus::Canceled ) {
		// Increment the counter (from another thread!  Note this isn't thread-safe in general!)
		this->counter++;

		// Wait 50ms
		WaitForSingleObjectEx(GetCurrentThread(), 50, FALSE);
	}

	// Once we've been canceled, clean up the threadHandle resources
	this->threadHandle->Close();
	this->threadHandle = nullptr;
}