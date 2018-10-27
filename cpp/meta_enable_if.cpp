#include <type_traits>
#include <vector>
#include <iostream>

namespace istd
{
	template<bool B, typename T>
	struct enable_if
	{};

	template<typename T>
	struct enable_if<true, T>
	{
		using type = T;
	};

	template<bool B, typename T>
	using Enable_if = typename enable_if<B, T>::type;
}

template<typename T, typename = istd::Enable_if<true, T>>
void fun(T val)
{
	std::cout << "fun called " << " val => " << val << std::endl;
}

int main()
{
	fun(2);
}