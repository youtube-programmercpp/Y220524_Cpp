#include <iostream>
#include <string>
struct node {
	std::string data;
	node* next = nullptr;

};
int main()
{
	node* 先頭 = new node;
	if (std::cin >> 先頭->data) {
		node* 末尾 = 先頭;
		for (;;) {
			末尾 = 末尾->next = new node;
			if (std::cin >> 末尾->data)
				continue;
			else
				break;
		}
	}

	for (node* p = 先頭;; ) {
		std::cout << '"' << p->data << '"' << '\n';
		p = p->next;
		if (p == nullptr)
			break;
	}
}
