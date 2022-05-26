#define	_CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h> //free �֐����g������
#include <iostream>
class String {
	char* s;
public:
	//�f�t�H���g�R���X�g���N�^
	String() noexcept
		: s{}
	{
	}
	//�f�X�g���N�^
	~String()
	{
		free(s);
	}
	//�ϊ��R���X�g���N�^1
	String(char*&& s) noexcept
		: s{s}
	{
		s = nullptr;
	}
	//�ϊ��R���X�g���N�^2
	String(const char* s) noexcept
		: String{ _strdup(s)}//����������t��...malloc
	{
	}
	//�ړ��R���X�g���N�^
	String(String&& r) noexcept
		: String{std::move(r.s)}
	{
	}
	String& operator=(String&& r) noexcept
	{
		std::swap(s, r.s);
		return *this;
	}
	size_t length() const noexcept
	{
		if (s)
			return strlen(s);
		else
			return 0;
	}
	String operator+(const String& r) const
	{
		const auto a = length();
		const auto b = r.length();
		if (auto p = static_cast<char*>(malloc(a + b + 1))) {
			strcpy(strcpy(p, s) + a, r.s);
			return { std::move(p) };
		}
		else
			throw std::bad_alloc();
	}

	friend std::ostream& operator<<(std::ostream& ostm, const String& r)
	{
		if (r.s)
			ostm << r.s;
		return ostm;
	}
};
int main()
{
	String s1;
	String s2{ "Test" };
	std::cout << s2 << '\n';

	//�ړ��R���X�g���N�^���Ăяo��
	String s3{ std::move(s2) };
	std::cout << "s2 = " << s2 << '\n';
	std::cout << "s3 = " << s3 << '\n';
	//�ړ�������Z�q���Ăяo��
	s2 = std::move(s3);
	std::cout << "s2 = " << s2 << '\n';
	std::cout << "s3 = " << s3 << '\n';
	//������A��
	s3 = String("�ǉ��̕�����");
	std::cout << "s2 + s3" << s2 + s3 << '\n';


}
