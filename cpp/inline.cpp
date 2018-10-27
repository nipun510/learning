
#include <iostream>
//If an inline function is 
//defined in more than one translation unit (e.g., typically because it was
//defined in a header; §15.2.2), its definition in the different translation units must be identica
inline int fact(int val)
{
	if(val == 0)
	{
		return 1;
	}
	return val*fact(val-1);
}
// If you want a guarantee that a value is
//computed at compile time, declare it constexpr 
//and make sure that all functions used in its evaluation are constexpr (

int main()
{
	std::cout << fact(6);
}