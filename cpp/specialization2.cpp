#include <iostream>


template <typename T>
struct A{};

template<typename T, typename U> // partial specialization
struct A<std::pair<T,U>>{};

template< typename T1, typename... U>
struct B{};

template <typename T1> // atleast 1 argument required in specialiazation
struct B<T1>{ using type = int;};

template <typename T1, typename T2>
struct B<T1, T2>{};


template <typename T1, typename T2>
struct C{};
template <typename T2>  // 2 template arguments required as in primary template
struct C<int, T2>{};

template<typename... T>
struct D{};


template<typename U>
void fun(){std::cout << "second" << std::endl;};
template<typename U, typename V>
void fun(){std::cout << "Third" << std::endl;};

int main()
{
	std::pair<int, int> p;
	A<decltype(p)> a;

	B<int> b;
	typename B<int>::type c;

	fun<int,int>();
}
