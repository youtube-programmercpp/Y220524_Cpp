#include <iostream>
#include <string>
class list {
	struct node {
		std::string data;
		node* next = nullptr;
	};
	node* �擪 = nullptr;
	node* ���� = nullptr;
public:
	//�����o�֐��i�܂��̓��\�b�h�Ƃ��j
	void push_back(std::string s)
	{
		if (�擪 == nullptr) {
			���� = �擪 = new node;
			�擪->data = s;
		}
		else {
			//�擪��nullptr
			node* �V�����m�[�h = new node;
			�V�����m�[�h->data = s;
			���� = ����->next = �V�����m�[�h;
		}
	}
	//�S�f�[�^���o��
	void show_all() const // const �����o
	{
		//p �� p != nullptr �Ɠ���
		for (node* p = �擪;p;p = p->next)
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
