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
void Test(const IUIAutomationPtr& pUIAutomation)
{
	if (const auto  Form1 = pUIAutomation->GetRootElement()->FindFirst
	( TreeScope_Descendants
	, pUIAutomation->CreateAndCondition
		( pUIAutomation->CreatePropertyCondition(UIA_ControlTypePropertyId, UIA_WindowControlTypeId)
		, pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, L"Form1")
		)
	)) {
		const auto textBox1 = Form1->FindFirst
		( TreeScope_Descendants
		, pUIAutomation->CreateAndCondition
			( pUIAutomation->CreatePropertyCondition(UIA_ControlTypePropertyId, UIA_EditControlTypeId)
			, pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, L"textBox1")
			)
		);
		const auto button1 = Form1->FindFirst
		( TreeScope_Descendants
		, pUIAutomation->CreateAndCondition
			( pUIAutomation->CreatePropertyCondition(UIA_ControlTypePropertyId, UIA_ButtonControlTypeId)
			, pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, L"button1")
			)
		);
		if (textBox1 && button1) {
			IUIAutomationValuePatternPtr {static_cast<IUIAutomationValuePattern *>(textBox1->GetCurrentPatternAs(UIA_ValuePatternId , const_cast<GUID*>(&__uuidof(IUIAutomationValuePattern )))), false}->SetValue(L"TEST");
			IUIAutomationInvokePatternPtr{static_cast<IUIAutomationInvokePattern*>(button1 ->GetCurrentPatternAs(UIA_InvokePatternId, const_cast<GUID*>(&__uuidof(IUIAutomationInvokePattern)))), false}->Invoke();
		}
	}
}
// --------------------------------------
int main()
{
	if (SUCCEEDED(CoInitializeEx(nullptr, COINIT_MULTITHREADED))) {
		try {
			// Prepare UIAutomation Object
			IUIAutomationPtr pUIAutomation;
			VerifyComError(pUIAutomation.CreateInstance(__uuidof(CUIAutomation)));
			Test(pUIAutomation);
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
