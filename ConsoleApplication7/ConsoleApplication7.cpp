// ConsoleApplication7.cpp : UI Automation 利用サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <Windows.h>

// --- UI Automation をある程度利用しやすくするための記述 ---
#include <UIAutomation.h>
#include <comdef.h>
#define	Macro(name)	_COM_SMARTPTR_TYPEDEF(name, __uuidof(name))
Macro(IUIAutomation         );
Macro(IUIAutomationCondition);
Macro(IUIAutomationElement  );
Macro(IUIAutomationValuePattern);
#undef	Macro
// COM の関数呼び出しが成功したことを確認する
void VerifyComError(HRESULT hr)
{
	if (FAILED(hr))
		_com_issue_error(hr);
}
// ----------------------------------------------------------

// --- UI Automation 応用サブルーチン ---
 // AutomationId に一致する条件を生成
IUIAutomationConditionPtr CreateAutomationIdPropertyCondition(const IUIAutomationPtr& pUIAutomation, const _variant_t& AutomationId)
{
	IUIAutomationConditionPtr pCondition;
	VerifyComError(pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, AutomationId, &pCondition));
	return pCondition;
}
// 条件に合う UI 要素を検索
IUIAutomationElementPtr FindElement(const IUIAutomationPtr& pUIAutomation, const IUIAutomationConditionPtr& pCondition)
{
	IUIAutomationElementPtr pRootElement;
	VerifyComError(pUIAutomation->GetRootElement(&pRootElement));

	IUIAutomationElementPtr found;
	VerifyComError(pRootElement->FindFirst(TreeScope_Descendants, pCondition, &found));
	return found;
}
// 条件に合う UI 要素の ValuePattern オブジェクトを取得
IUIAutomationValuePatternPtr ValuePatternByCondition(const IUIAutomationPtr& pUIAutomation, const IUIAutomationConditionPtr& pCondition)
{
	if (const auto pUIElement = FindElement(pUIAutomation, pCondition)) {
		IUIAutomationValuePatternPtr pValuePattern;
		VerifyComError(pUIElement->GetCurrentPatternAs(UIA_ValuePatternId, IID_IUIAutomationValuePattern, (void**) & pValuePattern));
		return pValuePattern;
	}
	else
		return nullptr;//該当なし
}
// --------------------------------------
int main()
{
	// CoInitializeEx(COINIT_MULTITHREADED) は UI Automation の使い初めに必要
	if (SUCCEEDED(CoInitializeEx(nullptr, COINIT_MULTITHREADED))) {
		try {
			// UIAutomation オブジェクトを用意
			IUIAutomationPtr pUIAutomation;
			VerifyComError(pUIAutomation.CreateInstance(CLSID_CUIAutomation));
			// AutomationId が "textBox1" である UI 要素の ValuePattern オブジェクトを取得し、そのテキスト内容を変更する
			if (const auto pValuePattern = ValuePatternByCondition(pUIAutomation, CreateAutomationIdPropertyCondition(pUIAutomation, L"textBox1")))
				pValuePattern->SetValue(_bstr_t(L"ConsoleApplication7で設定した文字列"));
		}
		catch (const _com_error& e) {
			OutputDebugString(e.ErrorMessage());
			OutputDebugString(TEXT("\n"));
		}
		// UI Automation を使い終わったら CoUninitialize を呼ぶ。（使い終わっていないのに呼んだら駄目）
		CoUninitialize();
	}
}
/*
* UI Automation 基本参考資料
* https://learn.microsoft.com/en-us/windows/win32/winauto/entry-uiauto-win32
*/
