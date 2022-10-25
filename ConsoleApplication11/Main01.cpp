//Visual Studio 2022
#include <stdio.h>
#include <iostream>
//gets の 宣言（declaration）が無いとエラー
extern "C" char* gets(char*);
int main()
{
	char buf[256];
	if (gets(buf))
		std::cout << "buf = \"" << buf << "\"" << std::endl;
}
