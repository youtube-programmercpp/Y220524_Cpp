#include "GetDlgItemTextW.h"

std::wstring GetDlgItemTextW(_In_ HWND hDlg, _In_ int nIDDlgItem)
{
	if (const auto hWnd = GetDlgItem(hDlg, nIDDlgItem)) {
		if (const auto TextLengthW = GetWindowTextLengthW(hWnd)) {
			std::wstring lpString;
			lpString.resize(TextLengthW);
			lpString.resize(GetWindowTextW(hWnd, &lpString.front(), TextLengthW + 1));
			lpString.shrink_to_fit();
			return lpString;
		}
		else
			return {};
	}
	else
		return {};
}
