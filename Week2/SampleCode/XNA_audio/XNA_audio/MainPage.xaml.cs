using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using XNA_audio.Resources;
using Microsoft.Xna.Framework.Audio;
using System.Windows.Threading;
using Microsoft.Xna.Framework;

namespace XNA_audio
{
    public partial class MainPage : PhoneApplicationPage

    {
        // The object that we read audio in from
        private Microphone audioIn = Microphone.Default;

        // The object we write audio out to
        private DynamicSoundEffectInstance audioOut = null;

        // The object that stores audio information as it flows from audioIn to audioOut
        private byte[] audioBuffer = null;

        // Constructor
        public MainPage()
        {
            InitializeComponent();

            DispatcherTimer timer = new DispatcherTimer();
            // Run it a little faster than our buffer updates
            timer.Interval = TimeSpan.FromMilliseconds(80);
            timer.Tick += OnTimerTick;
            timer.Start();
            FrameworkDispatcher.Update();

            // Add in the event handler for when a new buffer of audio is available
            audioIn.BufferReady += new EventHandler<EventArgs>(Microphone_BufferReady);

            // XNA is limited to 100ms latency. :(
            audioIn.BufferDuration = TimeSpan.FromMilliseconds(100);

            // Create a buffer of the appropriate length
            int bufferLen = audioIn.GetSampleSizeInBytes(audioIn.BufferDuration);
            audioBuffer = new byte[bufferLen];

            // Create our audio out interface with the same samplerate and channels of the audio input
            // We couldn't create this above because we needed to get audioIn.SampleRate
            audioOut = new DynamicSoundEffectInstance(audioIn.SampleRate, AudioChannels.Mono);

            // Start recording and playing
            audioIn.Start();
            audioOut.Play();
        }

        void OnTimerTick(object sender, EventArgs args)
        {
            FrameworkDispatcher.Update();
        }

        // The callback function that gets called by the FrameworkDispatcher
        private void Microphone_BufferReady(object sender, EventArgs e)
        {
            audioIn.GetData(audioBuffer);
            audioOut.SubmitBuffer(audioBuffer);
        }

    }
}