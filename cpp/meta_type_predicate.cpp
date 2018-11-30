#include <type_traits>
#include <iostream>

namespace istd
{
	template<typename T>
	struct Is_integral
	{
		static const bool value = false;
	};

	template<>
	struct Is_integral<int>
	{
		static const bool value = true;
	};
}

template<typename T>
void fun(T val)
{
	std::cout << istd::Is_integral<T>::value << std::endl;
}


int main()
{
	std::conditional<true, int, double> ::type val{23};
	fun(val);
}
