using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using CppThread.Resources;
using CounterThread;

namespace CppThread
{
    public partial class MainPage : PhoneApplicationPage
    {
        private CounterThreadClass thread = new CounterThreadClass();

        // Constructor
        public MainPage()
        {
            InitializeComponent();
        }

        private void updateButton_Click(object sender, RoutedEventArgs e)
        {
            valueText.Text = "Value: " + thread.getCounter();
        }

        private void startButton_Click(object sender, RoutedEventArgs e)
        {
            thread.start();
        }

        private void stopButton_Click(object sender, RoutedEventArgs e)
        {
            thread.stop();
        }
    }
}