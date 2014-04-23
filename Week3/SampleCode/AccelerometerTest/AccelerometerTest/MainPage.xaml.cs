using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using AccelerometerTest.Resources;
using Windows.Devices.Sensors;

namespace AccelerometerTest
{
    public partial class MainPage : PhoneApplicationPage
    {
        private Accelerometer acc = Accelerometer.GetDefault();

        // Constructor
        public MainPage()
        {
            InitializeComponent();

            // Sample code to localize the ApplicationBar
            acc.ReadingChanged += acc_ReadingChanged;
            acc.ReportInterval = acc.MinimumReportInterval;
        }

        void acc_ReadingChanged(Accelerometer sender, AccelerometerReadingChangedEventArgs args)
        {
            Dispatcher.BeginInvoke(() =>
            {
                accOut.Text = "Accelerometer: <" + args.Reading.AccelerationX + ", " + args.Reading.AccelerationY + ", " + args.Reading.AccelerationZ + ">";
            });
        }
    }
}