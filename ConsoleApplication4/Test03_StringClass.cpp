#include <cstring>
#include <algorithm>
#include <ostream>
#include <istream>
#include <string>
class String
{
public:
	typedef char value_type;
private:
	size_t       n        ;//保持している文字列の長さ(Null終端の分は含まない)
	value_type*  p        ;//文字列の先頭
public:
	String() noexcept
		: /*size_t       ;*/n        {}
		, /*value_type*  ;*/p        {}
	{
	}
	~String()
	{
		delete[]p;
	}
	String(size_t n)
		: /*size_t       ;*/n        {               n     }
		, /*value_type*  ;*/p        {new value_type[n + 1]}
	{
		p[n] = '\0';
	}
	String(const value_type* p, size_t n)
		: String{n}
	{
		std::memcpy(this->p, p, n);
	}
	//変換コンストラクタ
	String(const value_type* s)
		: String
			{ /*const value_type* p*/            s 
			, /*size_t            n*/std::strlen(s)
			}
	{
	}
	//移動コンストラクタ
	String(String&& r) noexcept
		: /*size_t       ;*/n        {r.n}
		, /*value_type*  ;*/p        {r.p}
	{
		r.n = 0      ;
		r.p = nullptr;
	}
	//移動代入演算子
	String& operator=(String&& r) noexcept
	{
		std::swap(/*size_t       ;*/n, r.n);
		std::swap(/*value_type*  ;*/p, r.p);
		return *this;
	}
	const value_type* c_str() const noexcept
	{
		if (p)
			return p;
		else
			return "";
	}
	String operator+(const String& rhs) const
	{
		String new_string(n + rhs.n);
		memcpy( new_string.p   ,     p,     n);
		memcpy(&new_string.p[n], rhs.p, rhs.n);
		return new_string;
	}
	size_t length() const noexcept
	{
		return n;
	}
	friend std::ostream& operator<<(std::ostream& ostm, const String& r)
	{
		if (r.p)
			return ostm.write(r.p, r.n);
		else
			return ostm;
	}
	friend std::istream& operator>>(std::istream& istm, String& r)
	{
		std::string s;
		if (istm >> s)
			r = {s.c_str(), s.length()};
		return istm;
	}
};
#include <stdio.h>
#include <iostream>

template<class T>void output(const T& s)
{
	printf("%s\n", s.c_str());
	printf("この文字列の長さは %zu です。\n", s.length());
}


int main()
{
#if 0
	String s1("ABCDEFGHIJKL");
	String s2;
	printf("s1 = %s\n", s1.c_str());
	printf("s2 = %s\n", s2.c_str());
	std::cout
		<< "s1 = " << s1 << '\n'
		<< "s2 = " << s2 << '\n'
		;
#endif
	String s1 = "ALPHA";
	String s2 = " BETA";
	String s3 = s1 + s2;

	output(s3);
	output(std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	typedef std::string::value_type char_type;
	typedef String::value_type      char_type;
}
