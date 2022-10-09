#include <iostream>
#include <stdexcept>

//ラムダ式 lambda expression
//Visual Studio 2010 から C++0x （C++11ではなくて）

//機械語（アセンブリ言語）… C 言語、C++ … 
//当時のシステム（CPU, メモリ）が貧弱だった

int main()
{
	try {
		while ([]()->bool
			{
				int n;
				if (std::cin >> n) {
					switch (n) {
					case -1:
						return false;
					default:
						std::cout << "入力されたデータ: " << n << '\n';
						return true;
					}
				}
				else
					throw std::runtime_error("入力エラー");
			
			}()) {
			//
		}


	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
