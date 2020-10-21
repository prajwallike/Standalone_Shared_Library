#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include <iostream>
using namespace std;

struct testclass
{
  /* use virtual otherwise linker will try to perform static linkage */
  virtual void testsomething() = 0;
  int y;
};

class MyClass
{
public:
  MyClass();
  
  MyClass(testclass* test, int a)
  {
    std::cout<<"inside parameterised constructor"<<"\n";
    test->testsomething();
    x = a;
  }

  /* use virtual otherwise linker will try to perform static linkage */
  virtual void DoSomething();

private:
  int x;
};

#endif