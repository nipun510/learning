#include <iostream>
#include <functional>

void fun(int & a)
{
	std::cout << a << std::endl;
}

int g = 10;
int gfun()
{
	std::cout << "inside gfun\n";
	return g;
}

int main()
{
//std::bind always copies its arguments, 
//but callers can achieve the effect of having an argument stored by
//reference by applying std::ref to it
	int a = 10;
	auto fun1 = std::bind(fun, std::ref(a));// a will passed as refrence.
	++a;
	fun1();
	auto fun2 = std::bind(fun, a); // a copy of a is binded 
	++a;
	fun2();// 11 will be printed
	std::cout << a << std::endl;


//expression will be evaluated when std::bind is called, 
//and the val resulting from that expression will be stored inside the resulting bind object. 
	auto gb1 = std::bind(fun, gfun()); // gfun evaluated here
	std::cout << "checkpoint2\n";
	--g;
	gb1(); 



}