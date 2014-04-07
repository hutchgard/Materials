#include "SimpleFFTWrapper.h"
#include <string.h>

using namespace SimpleFFTWrapper;
using namespace Platform;

FFTW::FFTW( unsigned int N ) {
	this->N = N;
	this->inputBuffer = (float*) fftwf_malloc(sizeof(float)*N);
	this->outputBuffer = (fftwf_complex *) fftwf_malloc(sizeof(fftwf_complex)*(N/2 + 1));

	this->plan = fftwf_plan_dft_r2c_1d( N, inputBuffer, outputBuffer, FFTW_MEASURE );
}

FFTW::~FFTW() {
	fftwf_destroy_plan( this->plan );
	fftwf_free( this->outputBuffer );
	fftwf_free( this->inputBuffer );
}

fftwf_complex * FFTW::fft( float * input ) {
	// First, we gotta copy input into inputBuffer.  :(
	memcpy( this->inputBuffer, input, sizeof(float)*this->N );

	// Make fftw do its magic
	fftwf_execute( this->plan );

	// The resultant spectrum is in outputBuffer!
	return this->outputBuffer;
}