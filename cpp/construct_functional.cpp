#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

template<typename Cont, typename Pred>
Cont filter(Cont source, Pred p)
{
	Cont target;
	std::remove_copy_if(source.begin(), source.end(), std::back_inserter(target), p);
	return target;
}


template<typename Cont, typename F>
Cont map(Cont source, F f)
{
	Cont target;
	std::transform(source.begin(), source.end(), std::back_inserter(target), f);
	return target;
}

template<typename Cont, typename F>
typename Cont::iterator::value_type reduce(Cont cont, F combine, const typename Cont::iterator::value_type & start)
{
	using elem_type = typename Cont::iterator::value_type;
	elem_type current = start;
	std::for_each(cont.begin(), cont.end(), [&current, &combine](elem_type elem){current = combine(current, elem);});
	return current;
}


void transform()
{
	std::string s{"hello how are you"};
	//trick to modify input sequence
	std::transform(s.begin(), s.end(), s.begin(), toupper);
	std::cout << s << std::endl;
}

void for_each()
{
	std::vector<int> v = {23,232,232,232323,23};
	std::for_each(v.begin(), v.end(), [](int a){std::cout << a << " ";});
	std::cout << std::endl;
	//modifying input sequece.
	std::for_each(v.begin(), v.end(), [](int & a){++a;});
	std::for_each(v.begin(), v.end(), [](int a){std::cout << a << " ";});
	std::cout << std::endl;

}

template<typename It, typename Out = std::ostream>
void print(It begin, It end, char sep = ' ', Out & out = std::cout)
{
	std::for_each(begin, end, [&out, sep](decltype(*begin) val){out << val << sep;});
	out << "\n";
}

template<typename Cont>
void print(Cont c)
{
	print(c.begin(), c.end());
}

void print(int a)
{
	std::cout << a << "\n";
}
void print(const std::string & s)
{
	std::cout << s << "\n";
}
int main()
{

	for_each();
	transform();

	std::vector<int> v1{1,3,5,7};
	
	auto l1 = [](int val){return val + 2;};
	print(map(v1, l1));

	auto l2 = [](int val){return val > 4;};
	print(filter(v1, l2));

	auto l3 = [](int a, int b){return a+b;};
	print(reduce(v1, l3, 0));

	std::vector<std::string> v2{"nipun", "nilesh", "mano"};
	auto l4 = [](const std::string & s1, const std::string & s2){return s1+s2;};

	print(reduce(v2, l4, ""));

	std::set<std::string> s1{"nipun", "nilesh"};
	auto l5 = [](const std::string s1, const std::string &s2){return s1+s2;};
	print(reduce(s1, l5, ""));
	//filter(v2, [](int val){return true;});


}
