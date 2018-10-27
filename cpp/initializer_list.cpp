#include <iostream>
#include <string>


class base
{
public:
	base()
	{
		std::cout << "default" << std::endl;
	}
	base(const int & a)
	{
		std::cout << "1 arg" << std::endl;
	}
	base(int a, int b)
	{
		std::cout << "2 arg" << std::endl;
	}
	base(std::initializer_list<int> list)
	{
		std::cout << "initializer list " << std::endl;
	}
};


void fun(std::initializer_list<int> list)
{
	std::cout << "initializer list called" << std::endl;
}

void fun(int val)
{
	std::cout << "1 arg called" << std::endl;
}

void fun()
{
	std::cout << "0 args called" << std::endl;
}
int main()
{
	base b{}; // calls default
	base b1{12,23}; // calls intializer list , constructor with 2 args not called
	//fun({});
	base b2{1}; // calls intializer list
	//std::string str("1010100100001");

	fun({12}); // initializer list called
	// 1 arg called in absence of initializer list

	fun({}); // initializer list called
	
}