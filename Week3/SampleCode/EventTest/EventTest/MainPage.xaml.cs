using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using EventTest.Resources;
using CppEvents;


namespace EventTest
{
    public partial class MainPage : PhoneApplicationPage
    {
        CppThread t = new CppThread();

        // Constructor
        public MainPage()
        {
            InitializeComponent();

            t.onTimerTick += t_onTimerTick;
        }

        // Getting called by C++
        void t_onTimerTick(int count)
        {
            int countTimesOneThousand = count * 1000;
            Dispatcher.BeginInvoke(() =>
            {
                output.Text = "Count: " + countTimesOneThousand;
            });
        }

        

    }
}