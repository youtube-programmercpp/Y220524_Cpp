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
		// 条件に合う UI 要素の ValuePattern オブジェクトを取得
		static ValuePattern ValuePatternByCondition(Condition pCondition)
		{
			var pUIElement = FindElement(pCondition);
			if (pUIElement == null)
				return null;
			else
				return (ValuePattern)pUIElement.GetCurrentPattern(ValuePattern.Pattern);
		}
		// --------------------------------------
		static void Main(string[] args)
		{
			// UIAutomation オブジェクトを用意
			var textBox1 = ValuePatternByCondition(CreateAutomationIdPropertyCondition("textBox1"));
			if (textBox1 != null)
				textBox1.SetValue("ConsoleApp2で設定した文字列");
		}
	}
}
