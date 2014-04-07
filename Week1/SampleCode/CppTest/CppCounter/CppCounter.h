#pragma once

namespace CppCounter
{
    public ref class FirstCppCounter sealed
    {
	private:
		int counter;
    public:
		FirstCppCounter();
		int incrementBy(int delta);
    };
}