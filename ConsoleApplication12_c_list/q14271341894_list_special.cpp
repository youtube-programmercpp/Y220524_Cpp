// C++ リスト実装特殊サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
//課題要件では「新たなリストを作る」とされているが、ここではその点を変更して、現状のリストの内容を改変するものとしてみた。
#include <stdio.h>
struct forward {
	int value;
	forward* next;
	void display(const char* leader) const
	{
		printf("%s%d", leader, value);
		if (next)
			next->display("-");
	}
	void arrange()
	{
		if (const auto first_even = next) {
			if (const auto next_odd = first_even->next) {
				(next = next_odd)->arrange2(first_even, first_even);
			}
		}
	}
private:
	void arrange2(forward* first_even, forward* prev_even)
	{
		if (const auto post_even = prev_even->next = next) {
			if (const auto next_odd = post_even->next)
				(next = next_odd)->arrange2(first_even, post_even);
			else
				next = first_even;
		}
		else
			next = first_even;
	}
};
int main()
{
	forward h = { 9     }
	,       g = { 6, &h }
	,       f = { 1, &g }
	,       e = { 7, &f }
	,       d = { 8, &e }
	,       c = { 3, &d }
	,       b = { 2, &c }
	,       a = { 4, &b }
	;
	a.display("入力:"); printf("\n");
	a.arrange();
	a.display("出力:"); printf("\n");
	return 0;
}
