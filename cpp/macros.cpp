//The auto, constexpr, const,
//decltype, enum, inline, lambda expressions, namespace, and template mechanisms can be used as
//better-behaved alternatives to many traditional uses of preprocessor constructs

#include <iostream>

//When writing a macro, it is not unusual to need a new name for something. A string can be created
//by concatenating two strings using the ## macro operator

#define NAME2(a,b) a##b

int NAME2(hack,cah)()
{
	int a = 12;
	return a;
}

//A single # before a parameter name in a replacement string 
//means a string containing the macroargument.

#define printx(x) std::cout << #x " = " << x << '\n';

int main()
{
	hackcah();

	int val = 12;//val = 12
	printx(val);
}