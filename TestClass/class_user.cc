#include <dlfcn.h>
#include <iostream>
#include "test.h"

using namespace std;

int main(int argc, char **argv)
{
  /* on Linux, use "./myclass.so" */
  void* handle = dlopen("MyClass.so", RTLD_LAZY);

  int abc;
  std::cout<<"enter an integer"<<std::endl;
  std::cin>>abc;

  //testclass *test = new testclass();
  testclass test;

  MyClass* (*create)(testclass, int);
  void (*destroy)(MyClass*);

  create = (MyClass* (*)(testclass, int))dlsym(handle, "create_object");
  destroy = (void (*)(MyClass*))dlsym(handle, "destroy_object");

  MyClass* myClass = (MyClass*)create(test, abc);
  myClass->DoSomething();
  destroy( myClass );

  //MyClass* (*create)(int);

  //testclass test;
  test.testsomething();//testsomething();
}
