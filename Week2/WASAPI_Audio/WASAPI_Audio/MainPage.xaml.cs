using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using WASAPI_Audio.Resources;
using WASAPI_Cpp;



namespace WASAPI_Audio
{
    public partial class MainPage : PhoneApplicationPage
    {

        private WASAPI_Cpp.WASAPI AudioLoop = new WASAPI_Cpp.WASAPI();

        // Constructor
        public MainPage()
        {
            InitializeComponent();

            // Sample code to localize the ApplicationBar
            //BuildLocalizedApplicationBar();
        }

        private void StartAudio_Tap(object sender, System.Windows.Input.GestureEventArgs e)
        {
            AudioLoop.startThread();
        }

        private void StopAudio_Tap(object sender, System.Windows.Input.GestureEventArgs e)
        {
            AudioLoop.stopThread();
        }
    }
}