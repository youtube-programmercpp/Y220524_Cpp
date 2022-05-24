#include <iostream>
#include <string>
//ノード(節)構造体
class node {
	std::string data;
	node* next; //次のノードへのポインタ
public:
	//コンストラクタ
	//データ移動
	node(std::string&& data, node* 最終ノード)
		: data(std::move(data)) //移動
		, next(最終ノード)
	{
		最終ノード->next = this;
	}
};



int main()
{
	std::string s;
	if (std::cin >> s) {
		//メモリ割り付け
		node* const first = new node(std::move(s));
		node* 最終ノード = first;

		for (;;) {
			if (std::cin >> s) {
				node* const next = new node(std::move(s), 最終ノード);
			}
		}




	}
}
