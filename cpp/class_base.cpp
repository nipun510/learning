#include <iostream>


class base
{
public:
	base(int value): val{value}{}
	virtual void fun(){std::cout << "base fun()" << std::endl;}
	int val;
};

class derived : public base
{
public:
	derived(int val1, int val2): val{val1}, base{val2}{}
	int val;
	void fun() override{std::cout << "derived fun()" << std::endl;}
};

void fun(base * b)
{
	std::cout << b->val << std::endl; // base value
	b->fun(); // derived fun called
}

int main()
{
	derived d{12, 23};
	fun(&d);
}