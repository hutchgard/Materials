#pragma once

using namespace Windows::Foundation;
using namespace Windows::System::Threading;

namespace CppTimer
{
	// Note; TimerCallback is now a TYPE.  I declare variables of this type to expose events!
	public delegate void TimerCallback(void);

    public ref class Timer sealed
    {
    public:
		// Setup and start a thread that calls the callback every `timeout` milliseconds
        Timer(unsigned int timeout);

		// Clean up threads
		virtual ~Timer();

		// The actual event that C# and C++ code can subscribe to
		event TimerCallback^ onTick;
	private:
		// Our internal thread that instigates the timer callbacks
		void timerThread( IAsyncAction^ operation );
		IAsyncAction^ threadHandle;

		// The number of milliseconds we will wait between callback invocations
		unsigned int timeout;

    };
}