// ConsoleApp3 : UI Automation 利用サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
using System;
using System.Runtime.InteropServices; // SendMessageA  を使用する上で有用となる記述
using UIAutomationClient            ; // UI Automation を使用する上で有用となる記述
namespace ConsoleApp3
{
	internal class Program
	{
		// --- UI Automation 応用サブルーチン ---
		// AutomationId 一致条件を生成
		static IUIAutomationCondition CreateAutomationIdPropertyCondition(IUIAutomation pUIAutomation, object AutomationId)
		{
			IUIAutomationCondition pCondition = pUIAutomation.CreatePropertyCondition(UIA_PropertyIds.UIA_AutomationIdPropertyId, AutomationId);
			return pCondition;
		}
		// 条件に合う UI 要素を検索
		static IUIAutomationElement FindElement(IUIAutomation pUIAutomation, IUIAutomationCondition pCondition)
		{
			IUIAutomationElement pRootElement = pUIAutomation.GetRootElement();
			return pRootElement.FindFirst(TreeScope.TreeScope_Descendants, pCondition);
		}
		// 条件に合う UI 要素の HWND を取得
		static IntPtr NativeWindowHandleByCondition(IUIAutomation pUIAutomation, IUIAutomationCondition pCondition)
		{
			var pUIElement = FindElement(pUIAutomation, pCondition);
			if (pUIElement == null)
				return IntPtr.Zero;//該当なし
			else
				return pUIElement.CurrentNativeWindowHandle;
		}
		// --------------------------------------
		// --- SendMessageA を使用するための記述 ---
		private const int WM_SETTEXT = 0x000C;
		[DllImport("user32.dll", CharSet = CharSet.Ansi)]
		public static extern IntPtr SendMessageA(IntPtr hWnd, int wMsg, IntPtr wParam, string lParam);
		// -----------------------------------------
		static void Main(string[] args)
		{
			try
			{
				// UIAutomation オブジェクトを用意
				IUIAutomation pUIAutomation = new CUIAutomation();
				// AutomationId が "textBox1" である UI 要素の HWND を取得し、そのテキスト内容を変更する
				var hWnd = NativeWindowHandleByCondition(pUIAutomation, CreateAutomationIdPropertyCondition(pUIAutomation, "textBox1"));
				if (hWnd != IntPtr.Zero)
					SendMessageA(hWnd, WM_SETTEXT, IntPtr.Zero, "ConsoleApp3で設定した文字列文字列");
			}
			catch (System.Exception e)
			{
				System.Diagnostics.Debug.WriteLine(e.Message);
			}
		}
	}
}
