#include <iostream>
//Consider using a run-time checked cast, such as narrow_cast<>(),
// for conversion between numeric types

class A
{
public:
	virtual void fun(){}
};

class B
{

public:
	void g(){}
	void fun(){}
};

int main()
{

	int a = 10;
	char c  = 'a';
	std::string s{"hello"};
	double d{12.90};

	float f{12.9};

//static_cast converts between related types such as one pointer type 
//to another in the same class hierarchy

//It does things like implicit conversions 

//static_cast performs no runtime checks. 
//This should be used if you know that you refer to an object 
//of a specific type at compile time, and thus a check would be unnecessary.
	
	int nd = static_cast<int>(d);
	//int ns = static_cast<int>(s); /*Ques1*/
	int nc = static_cast<char>(d);
	std::cout << nc << "\n";
	std::cout << nd << "\n";
//dynamic_cast does run-time checked conversion of pointers and references into a class hierarchy
//It returns a null pointer if the object referred to doesn't 
//contain the type casted to as a base class (when you cast to a reference, 
//a bad_cast exception is thrown in that case).
	A * aobj = new A{};
	B * bobj = new B{};

	bobj = dynamic_cast<B *>(aobj);
	if(bobj == NULL){std::cout << "NULL\n";}
	//bobj->fun();

//reinterpret_cast handles conversions between unrelated types such as an integer to a pointer
//or a pointer to an unrelated pointer type

	char x = 'a';
	//int∗ p1 = &x; // error : no implicit char* to int* conversion
	//int∗ p2 = static_cast<int∗>(&x); // error : no implicit char* to int* conversion
	//int *p3 = reinterpret_cast<int∗>(&x); // OK: on your head be it



// {} will perform only ‘‘well-behaved’’ conversions.
// {}-initializer notation does not allow narrowing 
//int val{112.2};invalid narrowing 

/*Output
compilation error invalid static_cast

*/	

}