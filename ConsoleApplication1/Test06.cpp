#include <iostream>
#include <string>
class list {
	struct node {
		std::string data;
		node* next = nullptr;
	};
	node* 先頭 = nullptr;
	node* 末尾 = nullptr;
public:
	//メンバ関数（またはメソッドとも）
	void push_back(std::string s)
	{
		if (先頭 == nullptr) {
			末尾 = 先頭 = new node;
			先頭->data = s;
		}
		else {
			//先頭≠nullptr
			node* 新しいノード = new node;
			新しいノード->data = s;
			末尾 = 末尾->next = 新しいノード;
		}
	}
	//全データを出力
	void show_all() const // const メンバ
	{
		//p は p != nullptr と同じ
		for (node* p = 先頭;p;p = p->next)
			std::cout << '"' << p->data << '"' << '\n';
	}
};
int main()
{
	std::string s;
	list a;
	while (std::cin >> s)
		a.push_back(s);
	a.show_all();
}
