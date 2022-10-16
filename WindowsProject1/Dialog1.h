#pragma once
#include <Windows.h>
class Dialog1
{
	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) noexcept;
public:
	INT_PTR static ShowDialog(_In_ HWND hWndParent) noexcept;
};
