#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "Person.h"

// use namespace to protect the name conflict against the member name of your class
// so before use your class as usual need using needed namespace firstly 
using namespace A;
using namespace std;

int test_case()
{
  // in cpp enhance the c struct to define func within struct directly
  // use class to replace struct to distinguish cpp enhance for the c struct
  cout << "use class to replace struct to distinguish cpp enhance for the c struct\n" << endl;
  Person per0;
  Person per1[2];
  per1[0].setName("zhangsan");
  per1[0].setAge(17);
  per1[1].setName("lisi");
  per1[1].setAge(18);
  int n;
  for(n=0; n<2; n++){
    per1[n].print_func_cpp(n);
  }
  Person per2("wangwu", 16);
  per2.print_func_cpp(2);
  Person *per3 = new Person("dingyi", 1);
  per3->print_func_cpp(3);
  Person *per4 = new Person[1];
  per4->setName("meiliu");
  per4->setAge(66);
  per4->print_func_cpp(4);

  delete per3;
  delete []per4;

  return 0;
}

int test_fun()
{
  Person per0;
  Person *per1 = new Person;
  return 0;
}

int fun()
{
  Student s(3, "bill", "lily", 18, 17);
}

int main(int argc, char **argv)
{
  test_case();
  sleep(10);
  fun();
  return 0;
}
