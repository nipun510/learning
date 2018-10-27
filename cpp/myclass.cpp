#include <iostream>
#include <myclass.hpp>

template<typename T>
void myclass::fun(T val)
{
    std::cout << " fun called " << std::endl;
}

template void myclass::fun<int>(int);
