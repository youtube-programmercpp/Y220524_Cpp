#include <iostream>
#include <string>
//�m�[�h(��)�\����
class node {
	std::string data;
	node* next; //���̃m�[�h�ւ̃|�C���^
public:
	//�R���X�g���N�^
	//�f�[�^�ړ�
	node(std::string&& data, node* �ŏI�m�[�h)
		: data(std::move(data)) //�ړ�
		, next(�ŏI�m�[�h)
	{
		�ŏI�m�[�h->next = this;
	}
};



int main()
{
	std::string s;
	if (std::cin >> s) {
		//����������t��
		node* const first = new node(std::move(s));
		node* �ŏI�m�[�h = first;

		for (;;) {
			if (std::cin >> s) {
				node* const next = new node(std::move(s), �ŏI�m�[�h);
			}
		}




	}
}
