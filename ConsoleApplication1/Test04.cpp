#include <iostream>
#include <string>
struct node {
	std::string data;
	node* next = nullptr;

};
int main()
{
	node* �擪 = new node;
	if (std::cin >> �擪->data) {
		node* ���� = �擪;
		for (;;) {
			���� = ����->next = new node;
			if (std::cin >> ����->data)
				continue;
			else
				break;
		}
	}

	for (node* p = �擪;; ) {
		std::cout << '"' << p->data << '"' << '\n';
		p = p->next;
		if (p == nullptr)
			break;
	}
}
