#include <iostream>
#include <list>
#include <string>
int main()
{
	//�^�̖��O             �ϐ���;
	std::list<std::string> list;

	for (;;) {
		std::string s;//������ϐ�
		if (std::cin >> s)//std::cin ����̓��͓��e�� s �ɓ����
			list.push_back(s);//list �� s ��ǉ�
		else
			break;//���͎��s ([Ctrl]+[Z]�L�[ ... EOF)
	}
#if 0
	//range-based for ��
	for (std::string s : list)
		std::cout << s << '\n';
#else
	//�ʂ̕��@(iterator)
	for (auto it = list.begin(); it != list.end(); ++it) {
		// *it �f�[�^�ɃA�N�Z�X�ł���
		std::cout << *it << '\n';
	}
#endif

}
