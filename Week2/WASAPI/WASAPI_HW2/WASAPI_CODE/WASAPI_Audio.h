#pragma once

#include <windows.h>

#include <synchapi.h>
#include <audioclient.h>
#include <phoneaudioclient.h>


using namespace Windows::Foundation;


namespace WASAPI_Audio
{
	public ref class WASAPI sealed
	{
	public:
		WASAPI();
		virtual ~WASAPI();
		
		// WASAPI functions
		
		void inputBufferHandler();


		// Threading functions
		void startThread();
		void stopThread();
		// This is the function that gets run in a new thread
		void thread(IAsyncAction^ operation);


	private:
		HRESULT Init_Capture();
		HRESULT Init_Render();

		// Device
		IAudioClient2 *inputDevice;
		IAudioClient2 *outputDevice;

		// Client
		IAudioCaptureClient *inputClient;
		IAudioRenderClient *outputClient;

		
		WAVEFORMATEX *inputFormat;
		HANDLE audioInEvent;
		HANDLE audioOutEvent;


		// The handle that will refer to the thread we will create
		IAsyncAction^ threadHandle;

	};



}