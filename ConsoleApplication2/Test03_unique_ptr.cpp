#include <crtdbg.h>
#include <cstring>
#include <memory>
int f()
{
	throw 1;
}
class constructor {
	std::unique_ptr<int[]> p;
	size_t                 n;
	int                    x;
public:
	constructor(size_t n)
		: p(new int[n])
		, n(        n )
		, x(f())
	{
	}
};
int main()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	try {
		constructor test(100);
	}
	catch (...) {
	}
}
