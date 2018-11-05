#include <iostream>

enum class unit_type{ daytype, monthtype, yeartype};


template<typename UnitType>
class Unit
{
    public:
    explicit Unit(int val): u(val){}
    operator int() const{ return u; }
    
    private:
    int u;
};

int  main()
{
    std::cout << "hello world" << std::endl;
   
      using day = Unit<unit_type::daytype>;
      using month = Unit<unit_type::monthtype>;
      using year = Unit<unit_type::yeartype>;
      
      day d(12);
      month m(12);
      year y(1);
      int a = d;
      std::cout << "hello " << std::endl;
}