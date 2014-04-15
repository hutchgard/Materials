#pragma once

using namespace Windows::Foundation;

namespace CppEvents
{
	public delegate void MyEvent(int count);

    public ref class CppThread sealed
    {
    public:
        CppThread();
		virtual ~CppThread();

		void doWork( int count );

		event MyEvent^ onTimerTick;
	private:
		void thread(IAsyncAction^ operation);

		int counter;
		IAsyncAction^ threadHandle;
    };
}