#include <iostream>

class weight
{
    friend weight operator"" _kg(long double w);
    friend weight operator"" _g(long double w);
    friend weight operator"" _kg(unsigned long long w);
    friend weight operator"" _g(unsigned long long w);
    
private:
    weight(double w){_weight = w;}
    double _weight;//in kg
    
public:
    inline double getWeight() const{return _weight;}
    weight operator + (const weight & rhs) const{return weight(_weight + rhs.getWeight());}
};

weight operator"" _kg(long double w){return weight(w);}
weight operator"" _g(long double w){return weight(w/1000);}
weight operator"" _kg(unsigned long long w){return weight(w);}
weight operator"" _g(unsigned long long w){return weight(w/1000);}

// Driver code 
int main() 
{ 
    auto w1 = 23.9_kg;
    auto w2 = 2000_g;
    auto w3 = w1 + w2;
    std::cout << w3.getWeight();
} 
