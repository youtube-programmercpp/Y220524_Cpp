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
		node* �擪 = new node;
		�擪->data = s;
		node* ���� = �擪;
		for (;;) {
			if (std::cin >> s) {
				node* �V�����m�[�h = new node;
				�V�����m�[�h->data = s;
				���� = ����->next = �V�����m�[�h;
			}
			else
				break;
		}
		for (node* p = �擪;; ) {
			std::cout << '"' << p->data << '"' << '\n';
			p = p->next;
			if (p == nullptr)
				break;
		}
	}
}
