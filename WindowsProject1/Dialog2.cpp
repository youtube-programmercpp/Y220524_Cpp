#include "Dialog2.h"
#include "resource.h"
#include <type_traits>
EXTERN_C extern std::remove_pointer_t<HMODULE> __ImageBase;

INT_PTR CALLBACK Dialog2::DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept
{
	switch (message) {
	case WM_INITDIALOG:
#define	ps	(reinterpret_cast<const std::wstring*>(lParam))
		SetDlgItemTextW(hDlg, IDC_EDIT1, ps->c_str());
		PostMessageW(GetDlgItem(hDlg, IDC_EDIT1), EM_SETSEL, -1, 0);
#undef	ps
		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
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
INT_PTR Dialog2::ShowDialog(_In_ HWND hWndParent, const std::wstring& s) noexcept
{
	return /*WINUSERAPI INT_PTR WINAPI*/::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */&__ImageBase
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG2)
	, /*_In_opt_ HWND      hWndParent    */hWndParent
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc
	, /*_In_     LPARAM    dwInitParam   */LPARAM(&s)
	);
}
