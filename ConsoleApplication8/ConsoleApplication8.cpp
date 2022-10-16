// ConsoleApplication8.cpp : UI Automation 利用サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <Windows.h>

// --- UI Automation を最大限利用しやすくするための記述 ---
#undef FindText
#pragma warning(push)
#pragma warning(disable : 26812)
#import "UIAutomationCore.dll" exclude("tagRECT", "tagPOINT")
#pragma warning(pop)
// COM の関数呼び出しが成功したことを確認する
void VerifyComError(HRESULT hr)
{
	if (FAILED(hr))
		_com_issue_error(hr);
}
using namespace UIAutomationClient;
// --------------------------------------------------------
// 
// --- UI Automation 応用サブルーチン ---
 // AutomationId に一致する条件を生成
IUIAutomationConditionPtr CreateAutomationIdPropertyCondition(const IUIAutomationPtr& pUIAutomation, const _variant_t& AutomationId)
{
	return pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, AutomationId);
}
// 条件に合う UI 要素を検索
IUIAutomationElementPtr FindElement(const IUIAutomationPtr& pUIAutomation, const IUIAutomationConditionPtr& pCondition)
{
	IUIAutomationElementPtr pRootElement = pUIAutomation->GetRootElement();
	IUIAutomationElementPtr found = pRootElement->FindFirst(TreeScope_Descendants, pCondition);
	return found;
}
// 条件に合う UI 要素の HWND を取得
HWND NativeWindowHandleByCondition(const IUIAutomationPtr& pUIAutomation, const IUIAutomationConditionPtr& pCondition)
{
	if (const auto pUIElement = FindElement(pUIAutomation, pCondition))
		return static_cast<HWND>(pUIElement->CurrentNativeWindowHandle);
	else
		return nullptr;//該当なし
}
// --------------------------------------
int main()
{
	if (SUCCEEDED(CoInitializeEx(nullptr, COINIT_MULTITHREADED))) {
		try {
			// UIAutomation オブジェクトを用意
			IUIAutomationPtr pUIAutomation;
			VerifyComError(pUIAutomation.CreateInstance(__uuidof(CUIAutomation)));
			if (const auto hWnd = NativeWindowHandleByCondition(pUIAutomation, CreateAutomationIdPropertyCondition(pUIAutomation, L"textBox1")))
				SendMessageA(hWnd, WM_SETTEXT, 0, LPARAM("C++プログラムから送信された文字列"));
		}
		catch (const _com_error& e) {
			OutputDebugString(e.ErrorMessage());
			OutputDebugString(TEXT("\n"));
		}
		CoUninitialize();
	}
}
/*
* UI Automation 参考資料
* https://learn.microsoft.com/en-us/windows/win32/winauto/entry-uiauto-win32
*/
