#include "Dialog1.h"
#include "Dialog2.h"
#include "GetDlgItemTextW.h"
#include "__ImageBase.h"
#include "resource.h"

INT_PTR CALLBACK Dialog1::DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept
{
	switch (message) {
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON1:
			(void)Dialog2::ShowDialog(hDlg, GetDlgItemTextW(hDlg, IDC_EDIT1));
			return true;
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return true;
		default:
			return false;
		}
	default:
		return false;
	}
}
INT_PTR Dialog1::ShowDialog(_In_ HWND hWndParent) noexcept
{
	return /*WINUSERAPI INT_PTR WINAPI*/::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */&__ImageBase
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG1)
	, /*_In_opt_ HWND      hWndParent    */hWndParent
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc
	, /*_In_     LPARAM    dwInitParam   */0
	);
}
