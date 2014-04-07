// CppCounter.cpp
#include "pch.h"
#include "CppCounter.h"

using namespace CppCounter;
using namespace Platform;

FirstCppCounter::FirstCppCounter()
{
	this->counter = 0;
}

int FirstCppCounter::incrementBy(int delta) {
	this->counter += delta;
	return this->counter;
}