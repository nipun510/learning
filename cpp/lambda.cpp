#include <iostream>
#include <functional>
#include <vector>
int g = 21;
int main()
{
	int c = 10;
//Captures apply only to non-static local variables
	static int  s = 23;//it's capture gives compilation error
	auto fun = [&c](int a, int b)->int
	{
		c = 100;
//don’t need to ‘‘capture’’ namespace variables (including global variables) because they are
//always accessible (provided they are in scope
		std::cout << g << std::endl;//
		return a+b+c;
	};

// operator()() for the generated function object (§11.4.1) is a const member
// function.

	auto fun2 = [&c](int a, int b) mutable
	{
		c = 20;
		return a + b + c;
	};
	fun2(12,32);
	std::cout << c << std::endl;
	std::cout << fun2(12, 32);




//• Use C++14’s init capture to move objects into closures.
//• In C++11, emulate init capture via hand-written classes or std::bind
	std::vector<double> data{12.3, 23.4, 232.2};
	auto func =
		std::bind( // C++11 emulation
			[](std::vector<double>& data) mutable // of init capture
					{ /* uses of data */ }, // for mutable lambda
			std::move(data)
);
}

//If the lifetime of a closure created from that lambda exceeds the lifetime of the local variable or
//parameter, the reference in the closure will dangle. 