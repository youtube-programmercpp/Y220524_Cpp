#include <Windows.h>

#include <type_traits> //�^�Ɋ֌W���邢�낢��ȃN���X���܂܂�Ă���

extern "C" extern std::remove_pointer_t<HINSTANCE> __ImageBase;

int main(int argc, char** argv)
{
	const auto hModule = GetModuleHandleA("KERNEL32.dll");
}
/*
�i�P�j__ImageBase ���g��     ... DLL�̏ꍇ�ɏd�󂷂�
�i�Q�jGetModuleHandle ���g�� ... EXE�p
�i�R�jnullptr �ŗǂ��ꍇ     ... EXE�p

C++/CLI �� DLL �ƂȂ�� DllMain �֐��������i�����Ȃ��j
hModule ���ǂ�����Ď擾���邩������ƂȂ�
*/