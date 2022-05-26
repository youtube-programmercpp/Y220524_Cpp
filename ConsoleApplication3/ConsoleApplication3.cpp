#include <iostream>
#include <string>

class Sample {
	std::string s;
public:
	//移動コンストラクタ
	Sample(std::string&& s) noexcept
		: s{ std::move(s)}
	{
	}
	Sample() noexcept
		: Sample(std::string{})
	{
	}
};

int main()
{
	std::string s{ "TEST" };
	Sample x( std::string{ s } );
	std::cout << s << '\n';
}
