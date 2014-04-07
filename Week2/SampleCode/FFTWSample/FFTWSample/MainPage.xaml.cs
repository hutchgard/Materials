using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using FFTWSample.Resources;
using SimpleFFTWrapper;

namespace FFTWSample
{
    public partial class MainPage : PhoneApplicationPage
    {
        CSharpBridge csb = new CSharpBridge();

        // Constructor
        public MainPage()
        {
            InitializeComponent();
        }

        private void goButton_Click(object sender, RoutedEventArgs e)
        {
            // Calculate the average DFT magnitude of 512 points of uniform [0,1] data.
            // An amazingly useless operation, but one that illustrates how to use FFTW nonetheless
            float avgMag = csb.avgMagnitudeOfRandomData(512);
            textOut.Text = "Avg. Magnitude: " + avgMag;
        }

    }
}