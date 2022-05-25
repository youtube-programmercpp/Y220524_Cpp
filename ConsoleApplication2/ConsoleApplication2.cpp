// ConsoleApplication2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
class Sample1 {
	int x;
	int y;
public:
	//constructor
	Sample1() noexcept //例外を投入しない関数であることを示す
		: x{}
		, y{}
	{
	}
	//destructor
	~Sample1()
	{
		//片付けを行いたいとき、ここに処理を記述する
		//資源 resource の解放
	}
};
int main()
{
	try {
		{
			Sample1 a;
			//a オブジェクトが破棄される
		}
		int x = 0;
	}
	catch (...) {
		//例外を捕捉
	}

}
