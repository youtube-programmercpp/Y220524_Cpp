#include <vector>
int main()
{
	std::vector<std::vector<int>> a;

	//�ϐ���p�ӂ��Ă��܂��ƁA���ꂪ�c��
	std::vector<int> b{1, 2, 3};

	a.push_back(b);//�ړ��ł͂Ȃ��R�s�[
	a.emplace_back(b);//�ړ��ł͂Ȃ��R�s�[
}
