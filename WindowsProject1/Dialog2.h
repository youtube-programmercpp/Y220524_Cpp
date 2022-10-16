#pragma once
#include <Windows.h>
#include <string>
class Dialog2
{
	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept;
public:
	INT_PTR static ShowDialog(_In_ HWND hWndParent, const std::wstring& s) noexcept;
};

