#include <iostream>

class base1
{
	int a = 10;
public:
	void fun()
	{
		std::cout << "base1::fun called" << a << "\n";
	}
};

class base2
{
	int a = 10;
public:
	virtual void fun()
	{
		std::cout << "base2::fun called" << a << "\n";
	}
};

class derived1 : public base1
{
	int a = 20;
public:
	void fun()
	{
		std::cout << "derived1::fun called " << a << "\n";
	}
};

class derived2 : public base2
{
public:
	int a = 20;
	virtual void fun()
	{
		std::cout << "derived2::fun called" << a << "\n";
	}
};

int main()
{
	base1 b1;
	base2 b2;
	derived1 d1;
	derived2 d2;

	
//In order to be a polymorphic type, your class must have at least one virtual function. 
//If your classes are not polymorphic types, the base-to-derived use of dynamic_cast will not compile.
// though derived-to-base will succed.
	
	base1 *b1ptr = dynamic_cast<base1 *>(&d1);
	b1ptr->fun();
	//derived1 *d1ptr = dynamic_cast<derived1 *>(&b1);

	//error: invalid conversion from ‘base1*’ to ‘derived1*’ 
	//derived1 *d1ptr3 = &b1;

	derived1 *d1ptr2 = static_cast<derived1 *>(&b1);
	d1ptr2->fun();
	

	base2 *b2ptr = dynamic_cast<base2 *>(&d2);
	b2ptr->fun();

	//warning: dynamic_cast of ‘base2 b2’ to ‘class derived2*’ can never succeed
	//Segmentation fault
	//derived2 *d2ptr = dynamic_cast<derived2 *>(&b2);
	//d2ptr->fun();
}