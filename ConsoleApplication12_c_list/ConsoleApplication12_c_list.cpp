// テスト実行メイン関数 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <Windows.h>
#undef main
extern "C" extern const IMAGE_DOS_HEADER __ImageBase;
int main()
{
	const auto& d = *PIMAGE_EXPORT_DIRECTORY(&LPCSTR(&__ImageBase)[PIMAGE_NT_HEADERS(&LPCSTR(&__ImageBase)[__ImageBase.e_lfanew])->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress]);
	const auto AddressOfFunctions = reinterpret_cast<const DWORD*>(&LPCSTR(&__ImageBase)[d.AddressOfFunctions]);
	const auto AddressOfNames = reinterpret_cast<const DWORD*>(&LPCSTR(&__ImageBase)[d.AddressOfNames]);
	//各プログラムの fake main 関数群を実行する
	for (DWORD i = 0; i < d.NumberOfNames; ++i) {
		const auto Address = &LPCSTR(&__ImageBase)[AddressOfFunctions[i]];
		const auto Name = &LPCSTR(&__ImageBase)[AddressOfNames[i]];
		std::cout
			<< "----------\n"
			<< static_cast<const void*>(Address) << '\t' << Name << '\n'
			<< "----------\n"
			;
		(*FARPROC(Address))();
	}

}
