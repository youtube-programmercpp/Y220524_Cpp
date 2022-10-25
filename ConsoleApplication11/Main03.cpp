#include <vector>
int main()
{
	std::vector<std::vector<int>> a;

	//変数を用意してしまうと、それが残る
	std::vector<int> b{1, 2, 3};

	a.push_back(b);//移動ではなくコピー
	a.emplace_back(b);//移動ではなくコピー
}
