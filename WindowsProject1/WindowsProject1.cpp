// WindowsProject1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "WindowsProject1.h"
#include "Dialog1.h"

int APIENTRY wWinMain
( _In_     HINSTANCE hInstance    
, _In_opt_ HINSTANCE hPrevInstance
, _In_     LPWSTR    lpCmdLine    
, _In_     int       nCmdShow     
)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine    );
	UNREFERENCED_PARAMETER(nCmdShow     );
	Dialog1::ShowDialog(nullptr);
	return EXIT_SUCCESS;
}
