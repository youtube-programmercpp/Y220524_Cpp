#define	_CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <new>

char* Duplicate(const char* s)
{
	if (const auto new_pointer = _strdup(s))
		return new_pointer;
	else
		throw std::bad_alloc();
}

class sample {
	char* s;
public:
	sample() noexcept
		: s()
	{
	}
	//copy constructor
	sample(const sample& r)
		: s{ Duplicate(r.s) }
	{
	}
	//assignment operator
	sample& operator=(const sample& r)
	{
		if (s == r.s)
			return *this;
		else {
			//���ʏ���
			const auto new_pointer = Duplicate(r.s);
			free(s);
			s = new_pointer;
			return *this;
		}
	}
	
	//destructor
	~sample()
	{
		free(s);
	}

	sample& operator++()
	{
		if (s) {
			//s ���� nullptr
			char t[sizeof "-2147483647"];
			const auto m = sprintf(t, "%d", atoi(s) + 1);
			if (const auto new_pointer = static_cast<char*>(malloc(m + 1))) {
				free(s);
				strcpy(s = new_pointer, t);
				return *this;
			}
			else
				throw std::bad_alloc();
		}
		else {
			//s �� nullptr
			if ((s = _strdup("1")) == nullptr)
				throw std::bad_alloc();
			else
				return *this;
		}
	}
};
int main()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	sample x; //�f�t�H���g�R���X�g���N�^���Ăяo�����
	++ ++ ++x;

	x = x;//���Q�ł���ׂ�

	sample y;
	y = y = x;//������Z�q���I�[�o�[���[�h����K�v����
}
