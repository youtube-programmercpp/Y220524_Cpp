#include <iostream>
#include <string>
struct node {
	std::string data;
	node* next = nullptr;

};
int main()
{
	node* æ“ª = new node;
	if (std::cin >> æ“ª->data) {
		node* ––”ö = æ“ª;
		for (;;) {
			––”ö = ––”ö->next = new node;
			if (std::cin >> ––”ö->data)
				continue;
			else
				break;
		}
	}

	for (node* p = æ“ª;; ) {
		std::cout << '"' << p->data << '"' << '\n';
		p = p->next;
		if (p == nullptr)
			break;
	}
}
