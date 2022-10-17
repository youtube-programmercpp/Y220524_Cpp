// ConsoleApp2 : UI Automation 利用サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
using System;
using System.Runtime.InteropServices; // SendMessageA  を使用する上で有用となる記述
using System.Windows.Automation     ; // UI Automation を使用する上で有用となる記述
namespace ConsoleApp2
{
	internal class Program
	{
		// --- UI Automation 応用サブルーチン ---
		// AutomationId に一致する条件を生成
		static Condition CreateAutomationIdPropertyCondition(object AutomationId)
		{
			return new PropertyCondition(AutomationElement.AutomationIdProperty, AutomationId);
		}
		// 条件に合う UI 要素を検索
		static AutomationElement FindElement(Condition pCondition)
		{
			return AutomationElement.RootElement.FindFirst(TreeScope.Descendants, pCondition);
		}
		// 条件に合う UI 要素の HWND を取得
		static int NativeWindowHandleByCondition(Condition pCondition)
		{
			var pUIElement = FindElement(pCondition);
			if (pUIElement == null)
				return 0;
			else
				return pUIElement.Current.NativeWindowHandle;
		}
		// --------------------------------------
		// --- SendMessageA を使用するための記述 ---
		private const int WM_SETTEXT = 0x000C;
		[DllImport("user32.dll", CharSet = CharSet.Ansi)]
		public static extern IntPtr SendMessageA(int hWnd, int wMsg, IntPtr wParam, string lParam);
		// -----------------------------------------
		static void Main(string[] args)
		{
			// UIAutomation オブジェクトを用意
			var hWnd = NativeWindowHandleByCondition(CreateAutomationIdPropertyCondition("textBox1"));
			if (hWnd != 0)
				SendMessageA(hWnd, WM_SETTEXT, IntPtr.Zero, "ConsoleApp2で設定した文字列");
		}
	}
}
