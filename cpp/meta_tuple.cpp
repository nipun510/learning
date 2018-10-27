#include <type_traits>
#include <iostream>

namespace istd
{
	template<typename Head, typename... Tail>
	class tuple : public tuple<Tail...>
	{
	public:
		using inherited = tuple<Tail...>;
		constexpr tuple(){}
		tuple(Head h, Tail... tail): head(h), inherited(tail...){}

		Head head;
	};

	template <typename Head>
	class tuple<Head>
	{
	public:
		tuple(Head h): head(h){}
		Head head;
	};


	template<int N, typename T, typename... Rest>
	struct getNth
	{
		static auto value(tuple<T, Rest...> * t) -> decltype(getNth<N-1, Rest...>::value(t))
		{
			return getNth<N-1, Rest...>::value(t);
		}
	};

	template<typename T, typename... Rest>
	struct getNth<0, T, Rest...>
	{
      	static T value(tuple<T, Rest...> * t)
      	{
      		return t->head;
      	}
	};

	template<size_t N, typename... Types>
	auto get(tuple<Types...>  t) -> decltype(getNth<N, Types...>::value(&t))
	{
		return getNth<N, Types...>::value(&t);
	}

	template<typename... Types>
	tuple<Types...> make_tuple(Types... types)
	{
		return tuple<Types...>(types...);
	} 

	template<size_t N, size_t S, typename... T>
	struct tuple_printer
	{
		static void print(const tuple<T...> & t)
		{
			std::cout << ", " << get<N>(t);
			tuple_printer<N+1, S, T...>::print(t);
		}
	};

	template<size_t N, typename... T>
	struct tuple_printer<N, N, T...>
	{
		static void print(const tuple<T...> & t)
		{
			std::cout << ", " << get<N>(t);
		}

	};

	template<typename T, typename... Types>
	std::ostream & operator << (std::ostream & cout, const tuple<T, Types...> & t)
	{
		cout << "{ ";
		tuple_printer<0, sizeof...(Types) - 1, Types...>::print(t);
		cout << " }";
		return cout;
	}

}
int main()
{
	auto t  = istd::make_tuple(23,43,45);
	std::cout << istd::get<1>(t) << std::endl;
	//auto val = istd::getNth<0, int, int,int>::value(&t); // prints 23
	std::cout << t;
}