#include <iostream>
#include <type_traits>


namespace istd
{
	struct substitution_failure{};

	template<typename T>
	struct substitution_succeded: std::true_type{};

	template<>
	struct substitution_succeded<substitution_failure> : std::false_type{};

	template<typename T>
	class get_f_result
	{
	private:
		template<typename U>
		static auto check(const U & u) -> decltype(f(u));
		static substitution_failure check(...);
	public:
		using type = decltype(check(std::declval<T>()));
	};

	template<typename T>
	struct has_f : substitution_succeded<typename get_f_result<T>::type >
	{};

}

template<typename T>//, typename = typename std::enable_if<istd::has_f<T>::value, T>::type>
int f(const T * val)
{
	std::cout << "fun called " << std::endl;
	return 12;
}


struct base{};

int main()
{
	//f<int>(23);
	base b;
	base * c;
	//using d = decltype(f(b)); 
	std::cout << istd::has_f<base>::value ;
	std::cout << istd::has_f<base *>::value ;
}