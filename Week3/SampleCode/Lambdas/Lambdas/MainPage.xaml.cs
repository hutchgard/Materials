using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Lambdas.Resources;
using CppTimer;
using System.Windows.Threading;

namespace Lambdas
{
    public partial class MainPage : PhoneApplicationPage
    {
        Timer t = new Timer(100);
        DispatcherTimer dt = new DispatcherTimer();

        int NormalCounter = 0;
        int NaiveCounter = 0;
        int SmartCounter = 0;
        // Constructor
        public MainPage()
        {
            InitializeComponent();
            dt.Interval = TimeSpan.FromMilliseconds(100);
            dt.Start();
        }

        private void NormalButton_Click(object sender, RoutedEventArgs e)
        {
            dt.Tick += (object inner_sender, EventArgs inner_e) =>
            {
                NormalCounter++;
                NormalOut.Text = "Value: " + NormalCounter;
            };
        }

        private void NaiveLambdaButton_Click(object sender, RoutedEventArgs e)
        {
            t.onTick += () =>
            {
                NaiveCounter++;
                NaiveOut.Text = "Value: " + NaiveCounter;
            };
        }
        private void SmartLambdaButton_Click(object sender, RoutedEventArgs e)
        {
            t.onTick += () =>
            {
                Dispatcher.BeginInvoke(() =>
                {
                    SmartOut.Text = "Value: " + SmartCounter;
                });
            };
        }


    }
}