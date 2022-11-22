// C++ std::list 使用サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <list>
typedef std::list<int> list;
list arrange(const list& input)
{
	if (input.empty())
		return {};
	else {
		list first  ;
		list second ;

		for (auto it = input.begin();;) {
			first.push_back(*it);
			if (++it == input.end())
				break;
			else {
				second.push_back(*it);
				if (++it == input.end())
					break;
			}
		}
		first.splice(first.end(), second);
		return first;
	}
}
std::ostream& operator<<(std::ostream& ostm, const list& r)
{
	auto it = r.begin();
	if (it != r.end()) {
		for (ostm << *it; ++it != r.end();)
			ostm.put('-') << *it;
	}
	return ostm;
}
int main()
{
	list input;
	input.push_back(4);
	input.push_back(2);
	input.push_back(3);
	input.push_back(8);
	input.push_back(7);
	input.push_back(1);
	input.push_back(6);
	input.push_back(9);
	std::cout << "入力:" << input  << '\n';
	const list output = arrange(input);
	std::cout << "出力:" << output << '\n';
	return EXIT_SUCCESS;
}
