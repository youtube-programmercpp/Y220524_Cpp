using System;
using System.Runtime.InteropServices;
using System.Windows.Automation;
namespace ConsoleApp2
{
	internal class Program
	{
		static Condition CreateAutomationIdPropertyCondition(object AutomationId)
		{
			return new PropertyCondition(AutomationElement.AutomationIdProperty, AutomationId);
		}
		static AutomationElement FindElement(Condition pCondition)
		{
			return AutomationElement.RootElement.FindFirst(TreeScope.Descendants, pCondition);
		}
		static int NativeWindowHandleByCondition(Condition pCondition)
		{
			var pUIElement = FindElement(pCondition);
			if (pUIElement != null)
				return pUIElement.Current.NativeWindowHandle;
			else
				return 0;
		}
		private const int WM_SETTEXT = 0x000C;
		[DllImport("user32.dll", CharSet = CharSet.Ansi)]
		public static extern IntPtr SendMessageA(int hWnd, int wMsg, IntPtr wParam, string lParam);
		static void Main(string[] args)
		{
			// UIAutomation オブジェクトを用意
			var hWnd = NativeWindowHandleByCondition(CreateAutomationIdPropertyCondition("textBox1"));
			if (hWnd != 0)
			{
				SendMessageA(hWnd, WM_SETTEXT, IntPtr.Zero, "C++プログラムから送信された文字列");
			}
		}
	}
}
