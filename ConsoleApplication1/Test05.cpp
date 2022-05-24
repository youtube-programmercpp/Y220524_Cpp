#include <iostream>
#include <string>
struct node {
	std::string data;
	node* next = nullptr;

};
int main()
{
	std::string s;
	if (std::cin >> s) {
		node* 先頭 = new node;
		先頭->data = s;
		node* 末尾 = 先頭;
		for (;;) {
			if (std::cin >> s) {
				node* 新しいノード = new node;
				新しいノード->data = s;
				末尾 = 末尾->next = 新しいノード;
			}
			else
				break;
		}
		for (node* p = 先頭;; ) {
			std::cout << '"' << p->data << '"' << '\n';
			p = p->next;
			if (p == nullptr)
				break;
		}
	}
}
