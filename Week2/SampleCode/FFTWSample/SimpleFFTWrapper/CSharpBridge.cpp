#include "SimpleFFTWrapper.h"
#include <stdlib.h>
#include <math.h>

using namespace SimpleFFTWrapper;
using namespace Platform;

CSharpBridge::CSharpBridge() {
}

// This is just a plain C++ function.  It doesn't belong to an object or anything, it just sits here.
float mag( float real, float imag ) {
	return sqrtf(real * real + imag * imag);
}


float CSharpBridge::avgMagnitudeOfRandomData( unsigned int N ) {
	// First, generate N samples of random data:
	float * data = new float[N];

	// Fill it up with uniformly distributed noise over the period [0, 1]
	for( unsigned int i=0; i<N; ++i )
		data[i] = rand()/(1.0f*RAND_MAX);

	// Create FFTW object to analyze the entire buffer
	FFTW * fftw = new FFTW(N);

	// Analyze data, gaining fourier transform.  Just as X is the fourier transform of x, DATA is the fourier transform of data
	fftwf_complex * DATA = fftw->fft(data);

	// Average magnitude of DATA
	float avgMag = 0;

	// Calculate the average magnitude of DATA.  Note that since DATA is an array of complex numbers, we first index to
	// a certain fftwf_complex value, (DATA[i]), and then index either the real or imaginary part (DATA[i][0] or DATA[i][1])
	for( unsigned int i=0; i<N/2+1; ++i )
		avgMag += mag(DATA[i][0], DATA[i][1]);

	// Don't forget to release data and fftw, otherwise we leak memory!
	// Note that we don't delete DATA.  This is because fftw will clean it up by itself.
	delete fftw;
	delete data;

	// Return the average magnitude
	return avgMag;
}