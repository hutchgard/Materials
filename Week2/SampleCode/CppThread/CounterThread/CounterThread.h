#pragma once

using namespace Windows::Foundation;

namespace CounterThread
{
    public ref class CounterThreadClass sealed
    {
	private:
		// Stores the counter that is apparently so important that we need a whole thread to increment it
		int counter;

		// The handle that will refer to the thread we will create
		IAsyncAction^ threadHandle;
    public:
		// Initialize things in the constructor
        CounterThreadClass();

		// Use a destructor to ensure that our threads are cleaned up properly at the end
		virtual ~CounterThreadClass();

		// This starts the thread, doing it's counting business
		void start();

		// This pauses the thread
		void stop();

		// This returns the value currently contained within counter
		int getCounter();

		// This is the function that gets run in a new thread
		void thread( IAsyncAction^ operation );
    };
}