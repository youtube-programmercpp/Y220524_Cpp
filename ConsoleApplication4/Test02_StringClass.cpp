#include <cstring>
#include <algorithm>
class String
{
	size_t n        ;//�ێ����Ă��镶����̒���
	char*  p        ;//������̐擪
public:
	String() noexcept
		: /*size_t ;*/n        {}
		, /*char*  ;*/p        {}
	{
	}
	~String()
	{
		delete[]p;
	}
	String(const char* s) noexcept
		: /*size_t ;*/n        {std::strlen(s)}
		, /*char*  ;*/p        {new char[n + 1]}
	{
		std::memcpy(p, s, n);
		p[n] = '\0';
	}
	//�ړ��R���X�g���N�^
	String(String&& r) noexcept
		: /*size_t ;*/n        {r.n}
		, /*char*  ;*/p        {r.p}
	{
		r.n = 0      ;
		r.p = nullptr;
	}
	//�ړ�������Z�q
	String& operator=(String&& r) noexcept
	{
		std::swap(/*size_t ;*/n, r.n);
		std::swap(/*char*  ;*/p, r.p);
		return *this;
	}
};
#include <vector>
int main()
{
	std::vector<String> a;
	a.emplace_back("XXXXXXXXXXXXXXXXXXXXXXXX");
	a.emplace_back("YYYYYYYYYYYYYYYYYYYYYYYY");
	a.push_back({"XXXXXXXXXXXXXXXXXXXXXXXX"});
	a.push_back({"YYYYYYYYYYYYYYYYYYYYYYYY"});
}
