#ifndef __TEST_H__
#define __TEST_H__

class testclass
{
public:
  testclass()
  {
      y = 50;
  }

  /* use virtual otherwise linker will try to perform static linkage */
  virtual void testsomething()
  {
    std::cout<<"class_user::test_class::"<<y<<"\n";
  }
  private:
    int y;
};

class MyClass
{
public:
  //MyClass();
  MyClass(testclass test, int a)
  {
    test.testsomething();
    x = a;
  }

  /* use virtual otherwise linker will try to perform static linkage */
  virtual void DoSomething();

private:
  int x;
};

#endif
