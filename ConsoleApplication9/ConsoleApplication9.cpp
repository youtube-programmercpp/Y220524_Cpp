// ConsoleApplication9.cpp : UI Automation 利用サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <Windows.h>
#include <UIAutomation.h> // UI Automation を利用するための記述
int main()
{
	// CoInitializeEx(COINIT_MULTITHREADED) は UI Automation の使い初めに必要
	HRESULT hr;
	if (SUCCEEDED(hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED))) {
		// AutomationId が "textBox1" である UI 要素の HWND を取得し、そのテキスト内容を変更する

		// UIAutomation オブジェクトを用意
		IUIAutomation* pUIAutomation;
		if (SUCCEEDED(hr = CoCreateInstance(CLSID_CUIAutomation, nullptr, CLSCTX_INPROC_SERVER, IID_IUIAutomation, (void**)&pUIAutomation))) {
			// AutomationId に一致する条件を生成
			IUIAutomationCondition* pCondition;
			VARIANT AutomationId;
			AutomationId.vt = VT_BSTR;
			AutomationId.bstrVal = SysAllocString(L"textBox1");
			if (SUCCEEDED(hr = pUIAutomation->CreatePropertyCondition(UIA_AutomationIdPropertyId, AutomationId, &pCondition))) {
				// 条件に合う UI 要素を検索
				IUIAutomationElement* pRootElement;
				if (SUCCEEDED(hr = pUIAutomation->GetRootElement(&pRootElement))) {
					IUIAutomationElement* pUIElement;
					if (SUCCEEDED(hr = pRootElement->FindFirst(TreeScope_Descendants, pCondition, &pUIElement))) {
						if (pUIElement) {
							// 条件に合う UI 要素の HWND を取得
							UIA_HWND hWnd;
							if (SUCCEEDED(hr = pUIElement->get_CurrentNativeWindowHandle(&hWnd))) {
								if (hWnd) {
									// テキスト内容を変更
									SendMessageA(HWND(hWnd), WM_SETTEXT, 0, LPARAM("ConsoleApplication9で設定した文字列"));
								}
							}
							pUIElement->Release();
						}
					}
					pRootElement->Release();
				}
				pCondition->Release();
			}
			(void)VariantClear(&AutomationId);
			pUIAutomation->Release();
		}
		// UI Automation を使い終わったら CoUninitialize を呼ぶ。（使い終わっていないのに呼んだら駄目）
		CoUninitialize();
	}
}
/*
* UI Automation 基本参考資料
* https://learn.microsoft.com/en-us/windows/win32/winauto/entry-uiauto-win32
*/
