#include "pch.h"
#include <stdlib.h>
#include <math.h>
#include "WASAPI_Cpp.h"

using namespace Platform;
using namespace WASAPI_Cpp;


CSharpBridge::CSharpBridge() {
}

// This is just a plain C++ function.  It doesn't belong to an object or anything, it just sits here.
float mag(float real, float imag) {
	return sqrtf(real * real + imag * imag);
}


float CSharpBridge::loudestFrequency(unsigned int N) {
	float ret = 0;

	return ret;
}

