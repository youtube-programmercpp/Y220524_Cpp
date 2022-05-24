#include <iostream>
#include <list>
#include <string>
int main()
{
	//型の名前             変数名;
	std::list<std::string> list;

	for (;;) {
		std::string s;//文字列変数
		if (std::cin >> s)//std::cin からの入力内容を s に入れる
			list.push_back(s);//list に s を追加
		else
			break;//入力失敗 ([Ctrl]+[Z]キー ... EOF)
	}
#if 0
	//range-based for 文
	for (std::string s : list)
		std::cout << s << '\n';
#else
	//別の方法(iterator)
	for (auto it = list.begin(); it != list.end(); ++it) {
		// *it データにアクセスできる
		std::cout << *it << '\n';
	}
#endif

}
