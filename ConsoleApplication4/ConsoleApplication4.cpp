#include <iostream>
#include <vector>

class Test {
public:
	// デフォルトコンストラクタ
	Test(     ) noexcept
	{
	}
	Test(int x, int y, int z) noexcept
	{
	}
	Test(const char* p, const char* q) noexcept
	{
	}
};


int main()
{
	std::vector<Test> a;
	a.push_back   ({10, 20, 30});
	a.emplace_back( 10, 20, 30 );
}
