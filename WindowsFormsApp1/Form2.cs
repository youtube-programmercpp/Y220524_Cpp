using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
	public partial class Form2 : Form
	{
		public Form2()
		{
			InitializeComponent();
		}
		public static DialogResult ShowDialog(string s)
		{
			var instance = new Form2();
			instance.textBox1.Text = s;
			return instance.ShowDialog();
		}

		private void Form2_Load(object sender, EventArgs e)
		{			
			textBox1.SelectionStart = textBox1.TextLength;
		}
	}
}
