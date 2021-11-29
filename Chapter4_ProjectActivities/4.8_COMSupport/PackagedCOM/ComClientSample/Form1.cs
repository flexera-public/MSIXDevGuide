using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace ComClientSample
{
    public partial class Form1 : Form
    {
        [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        static extern int GetCurrentPackageFullName(ref int packageFullNameLength, StringBuilder packageFullName);

        MFCComServerBGColorTest.MFCComServerBGColorTest _comServer = null;
        public bool IsRunningAsUWPContaner()
        {
            if (IsWindows7OrBelow())
                return false;

            int length = 0;
            StringBuilder sb = new StringBuilder(0);
            int ret = GetCurrentPackageFullName(ref length, sb);

            sb = new StringBuilder(length);
            ret = GetCurrentPackageFullName(ref length, sb);

            return ret != 15700L; // Appmodel with error (no package)
        }

        private bool IsWindows7OrBelow()
        {
            
            int verMajor = Environment.OSVersion.Version.Major;
            int verMinor = Environment.OSVersion.Version.Minor;
            double ver = verMajor + (double)verMinor / 10;
            return ver <= 6.1;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (IsRunningAsUWPContaner())
            {
                label2.Text = "I'm running inside a UWP container";
            }
            else
            {
                label2.Text = "I'm running as a native desktop app";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (_comServer == null)
                _comServer = new MFCComServerBGColorTest.MFCComServerBGColorTest();

            if(!String.IsNullOrEmpty(textBox1.Text))
                _comServer.color = textBox1.Text;
        }
    }
}
