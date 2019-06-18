#include <iostream>

//https://en.wikipedia.org/wiki/Data_structure_alignment
//https://eli.thegreenplace.net/2012/12/17/dumping-a-c-objects-memory-layout-with-clang/
//http://www.drdobbs.com/cpp/storage-layout-of-polymorphic-objects/240012098
//https://www.urbanpro.com/c-language/memory-layout-in-c-vis-a-vis-polymorphism
//http://hacksoflife.blogspot.com/2007/02/c-objects-part-1-basic-object-memory.html

/*
 Both the C and C++ standards state that structure alignment is implementation-defined. 
 Therefore each compiler may choose to align data differently, resulting in different and incompatible data layouts
 */

struct X
{
     char c;
     char d;
     //padding 2 bytes
     int i;
     //padding 0 bytes
};

struct B
{
     char c;
     //padding 3 bytes
     int i;
     char d;
     //padding 3 bytes
};


class A{
  public:
  virtual void fun1(){}
};//size=8 bytes

class B  {
  public:
  char c[8];
  virtual void fun2(){}

};//size=16 bytes

class C:public A, public B{
};//size= 8 + 16 = 24 bytes





class A1{
      public:
            virtual void fun(){}
};

class B1 : virtual public A1{
};

class C1 : virtual public A1{
};

class D1: public B1, public C1{
};



int main(){
  A a;
  B b;
  C c;
  int val = 23;
  int * ptr = & val;
  std::cout << sizeof(int) << " " << sizeof(ptr) << "\n";
  std::cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << "\n";


  A1 a1;
  B1 b1;
  C1 c1;
  D1 d1;
  std::cout << sizeof(a1) << " " << sizeof(b1) << "  " << sizeof(c1) << " " << sizeof(d1) << "\n";
  // 8 8  8 16
}
/*
4 8
8 16 24
*/
