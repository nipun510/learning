#include <iostream>

/**************** class template specialization ***************/
template<typename T>
class A;

template<>
class A<int> // complete specialization
{
public:
	void fun()
	{
		std::cout << "fun called" << std::endl;
	}
};


template<typename T> // partial specialization
class A<T*>
{
public:
	void fun()
	{
		std::cout << "fun called" << std::endl;
	}
};
/**************** Function template specialization ***************/
template<typename T>
void fun(T val)
{
	std::cout << "primary template " << val << std::endl;
}

template<>
void fun(int val) // partial specialization not allowed
{
	std::cout << "complete specialization of fun function template " << std::endl;
}


void fun(int val)
{
	std::cout << "non templated fun" << std::endl;
}
int main()
{
	A<int> a;
	A<int*> b;
	//A<double> b;
	a.fun();//run fines even if primary template is just declared and not defined.
	b.fun();
	
	fun(10.90);
}