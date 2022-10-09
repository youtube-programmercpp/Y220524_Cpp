#include <Windows.h>

#include <type_traits> //型に関係するいろいろなクラスが含まれている

extern "C" extern std::remove_pointer_t<HINSTANCE> __ImageBase;

int main(int argc, char** argv)
{
	const auto hModule = GetModuleHandleA("KERNEL32.dll");
}
/*
（１）__ImageBase を使う     ... DLLの場合に重宝する
（２）GetModuleHandle を使う ... EXE用
（３）nullptr で良い場合     ... EXE用

C++/CLI の DLL となると DllMain 関数が無い（書けない）
hModule をどうやって取得するかが大問題となる
*/