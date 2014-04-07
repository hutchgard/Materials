using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using CppTest.Resources;
using CppCounter;

namespace CppTest
{
    public partial class MainPage : PhoneApplicationPage
    {
        private FirstCppCounter cppCounter = new FirstCppCounter();

        // Constructor
        public MainPage()
        {
            InitializeComponent();
        }

        private void incButton_Click(object sender, RoutedEventArgs e)
        {
            int result = cppCounter.incrementBy(2);
            this.textOut.Text = "Counter: " + result;
        }
    }
}