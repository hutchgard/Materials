#pragma once
#include "include/fftw3.h"

/*
	This file shows how to mix pure C++ and C++/CX within a single project.
	We have one class, FFTW, which is a pure C++ class that does all the heavy lifting for FFTW.
	We also have another class, CSharpBridge, which is a C++/CX class allowing interaction with C#.

	Why do we do this?  Because in Homework 2, you will need to pass arrays to this class, which we can't do from C#. (Yet!)
	Therefore, for Homework 2 you should create a C++/CX class similar to CSharpBridge to do all WASAPI-related work, but which
	is able to call out to FFTW when it needs to perform a Fourier Transform.  In that way, you will be able to 
	start/stop WASAPI recording via C#, ask for dominant frequency information via C#, and still do FFTs on the data in C++.
*/

namespace SimpleFFTWrapper
{
	// Note, this is a PURE C++ class!  It cannot be called from C#, all that has to happen through the wrapper class below!
    class FFTW
    {
	private:
		// Internally managed buffers
		float * inputBuffer;
		fftwf_complex * outputBuffer;

		// Length of buffers
		unsigned int N;

		// The fftw plan we generate in the constructor
		fftwf_plan plan;
	public:
        // Creates an FFTW object tuned for a certain length buffer
		FFTW( unsigned int N );

		// Cleanup the internal buffers allocated
		~FFTW();

		// Returns Fourier transform of input.  Because input is real, we
		// exploit the Hermitian Symmetry property of the FT of a real input,
		// omitting the negative frequencies. Practically,this means that if
		// the input is of length N, the output will be of length (N/2) + 1
		fftwf_complex * fft( float * input );
	};


	public ref class CSharpBridge sealed
	{
	public:
		// Constructor
		CSharpBridge();

		// Take the fourier transform of random data of length N, return average magnitude
		// Note: This is a pretty useless operation, this is just to demonstrate how to use FFTW
		float avgMagnitudeOfRandomData( unsigned int N );
	};
}