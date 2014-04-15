// CppTimer.cpp
#include "CppTimer.h"
#include <windows.h>

using namespace CppTimer;
using namespace Platform;

Timer::Timer(unsigned int timeout)
{
	this->timeout = timeout;

	threadHandle = ThreadPool::RunAsync( ref new WorkItemHandler(this, &Timer::timerThread) );
}

Timer::~Timer() {
	threadHandle->Cancel();
}

void Timer::timerThread( IAsyncAction^ operation ) {
	while( operation->Status != AsyncStatus::Canceled ) {
		WaitForSingleObjectEx(GetCurrentThread(), this->timeout, FALSE);

		// Trigger event!
		this->onTick();
	}
	operation->Close();
}