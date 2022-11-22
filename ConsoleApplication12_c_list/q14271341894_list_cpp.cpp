// C++ リスト実装サンプル Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
class list {
	struct node {
		int   n   ;
		node* next;
	};
	node* front;
	node* back ;
public:
	class const_iterator {
		friend list;
		const node* const *p;
	public:
		const_iterator(const node* const* p) noexcept
			: p{p}
		{
		}
		const_iterator& operator++() noexcept
		{
			p = &(*p)->next;
			return *this;
		}
		const int& operator*() const noexcept
		{
			return (*p)->n;
		}
		bool operator==(const const_iterator& r) const noexcept
		{
			return p == r.p;
		}
		bool operator!=(const const_iterator& r) const noexcept
		{
			return !operator==(r);
		}
	};
	class iterator {
		friend list;
		node** p;
	public:
		iterator(node** p) noexcept
			: p{p}
		{
		}
		iterator& operator++() noexcept
		{
			p = &(*p)->next;
			return *this;
		}
		int& operator*() const noexcept
		{
			return (*p)->n;
		}
		bool operator==(const iterator& r) const noexcept
		{
			return p == r.p;
		}
		bool operator!=(const iterator& r) const noexcept
		{
			return !operator==(r);
		}
	};
	list() noexcept
		: front{}
		, back {}
	{
	}
	list(list&& r) noexcept
		: front{r.front}
		, back {r.back }
	{
		r.front = r.back = nullptr;
	}
	list& operator=(list&& r) noexcept
	{
		if (this != &r) {
			this->~list();
			front = r.front;
			back  = r.back ;
			r.front = r.back = nullptr;
		}
		return *this;
	}
	~list()
	{
		while (front) {
			const auto front_next = front->next;
			delete front;
			front = front_next;
		}
	}
	void push_back(int n)
	{
		(this->front ? this->back->next : this->front) = this->back = new node{ n };
	}
	bool empty() const noexcept
	{
		return front == nullptr;
	}
	const_iterator begin() const noexcept{return { back ? &front      : &back };}
	      iterator begin()       noexcept{return { back ? &front      : &back };}
	const_iterator end  () const noexcept{return { back ? &back->next : &back };}
	      iterator end  ()       noexcept{return { back ? &back->next : &back };}
	void splice(iterator position, list& x)
	{
		auto original = *position.p;
		*position.p = x.front;
		if (original)
			x.back->next = original;
		else
			back = x.back;
		x.front = x.back = nullptr;
	}
};
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
