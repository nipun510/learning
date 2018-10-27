#include <iostream>
#include <vector>

template <typename T>
class base
{
public:
	T val;
	base() = default;
	template<typename U>
	base(U v):val{v}{}
/*
	base(const base  & b)
	{
		val = b.val;
		std::cout << "copy constructor called" << std::endl;
	}
*/
	template<typename U>
	base(base<U> const & o)
	{
		std::cout << "templated copy constructor " << std::endl;
	}
	void fun();

};

template<typename T>
void base<T>::fun()
{
	std::cout << "fun called, val => " << val << std::endl;
}


template<typename T> 
class derived : public base<T>
{
public:
	void fun1();
};

template<typename T>
void derived<T>::fun1()
{
	// accessing templated base class members
	std::cout << "derived fun1 called " << base<T>::val << " or " << this->val << std::endl;
}

int main()
{
	base<int> b1;
	base<double> b2;
	

	base<int> c1(b1); // default copy constructor as b1 is base<int> same as c1
	base<int> c2(b2); // templated copy constructor

	derived<int> d;
	d.fun1(); // derived fun1 called
}