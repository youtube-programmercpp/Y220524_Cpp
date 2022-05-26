#define	_CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h> //free 関数を使うため
#include <iostream>
class String {
	char* s;
public:
	//デフォルトコンストラクタ
	String() noexcept
		: s{}
	{
	}
	//デストラクタ
	~String()
	{
		free(s);
	}
	//変換コンストラクタ1
	String(char*&& s) noexcept
		: s{s}
	{
		s = nullptr;
	}
	//変換コンストラクタ2
	String(const char* s) noexcept
		: String{ _strdup(s)}//メモリ割り付け...malloc
	{
	}
	//移動コンストラクタ
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

	//移動コンストラクタを呼び出す
	String s3{ std::move(s2) };
	std::cout << "s2 = " << s2 << '\n';
	std::cout << "s3 = " << s3 << '\n';
	//移動代入演算子を呼び出す
	s2 = std::move(s3);
	std::cout << "s2 = " << s2 << '\n';
	std::cout << "s3 = " << s3 << '\n';
	//文字列連結
	s3 = String("追加の文字列");
	std::cout << "s2 + s3" << s2 + s3 << '\n';


}
