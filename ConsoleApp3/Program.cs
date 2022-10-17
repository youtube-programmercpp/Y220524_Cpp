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
		// 条件に合う UI 要素の ValuePattern オブジェクトを取得
		static IUIAutomationValuePattern ValuePatternByCondition(IUIAutomation pUIAutomation, IUIAutomationCondition pCondition)
		{
			var pUIElement = FindElement(pUIAutomation, pCondition);
			if (pUIElement == null)
				return null;//該当なし
			else
				return (IUIAutomationValuePattern)pUIElement.GetCurrentPattern(UIA_PatternIds.UIA_ValuePatternId);
		}
		static void Main(string[] args)
		{
			try
			{
				// UIAutomation オブジェクトを用意
				IUIAutomation pUIAutomation = new CUIAutomation();
				// AutomationId が "textBox1" である UI 要素の ValuePattern を取得し、そのテキスト内容を変更する
				var textBox1 = ValuePatternByCondition(pUIAutomation, CreateAutomationIdPropertyCondition(pUIAutomation, "textBox1"));
				if (textBox1 != null)
					textBox1.SetValue("ConsoleApp3で設定した文字列");
			}
			catch (System.Exception e)
			{
				System.Diagnostics.Debug.WriteLine(e.Message);
			}
		}
	}
}
