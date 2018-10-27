#include <iostream>

//a constexpr function must consist of a single return-statement; 
//no loops , no if-statement and no local variables are allowed. 
//Also, a constexpr function may not have side effects


//A constexpr function allows recursion and conditional expressions
constexpr int fact(int val)
{
	return val > 1 ? fact(val-1) : 1; 
}
//fundamental role of constexpr functions
// as parts of constant expression evaluation
int main()
{
	constexpr int ans = fact(8);
	std::cout << ans << std::endl;
}