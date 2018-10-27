#include <iostream>
//Consider using a run-time checked cast, such as narrow_cast<>(),
// for conversion between numeric types

int main()
{

	int a = 10;
	char c  = 'a';
	std::string s{"hello"};
	double d{12.90};

	float f{12.9};

//static_cast converts between related types such as one pointer type 
//to another in the same class hierarchy
	int nd = static_cast<int>(d);
	//int ns = static_cast<int>(s); compilation error invalid static_cast
	int nc = static_cast<char>(d);
	std::cout << nc << "\n";
	std::cout << nd << "\n";

//reinterpret_cast handles conversions between unrelated types such as an integer to a pointer
//or a pointer to an unrelated pointer type

	char x = 'a';
	//int∗ p1 = &x; // error : no implicit char* to int* conversion
	//int∗ p2 = static_cast<int∗>(&x); // error : no implicit char* to int* conversion
	//int *p3 = reinterpret_cast<int∗>(&x); // OK: on your head be it

//dynamic_cast does run-time checked conversion
// of pointers and references into a class hierarchy

	//int val{112.2};invalid narrowing 

}