#include <stdio.h>
#include <iostream>
#include "Person.h"

// use namespace to protect the name conflict against the member name of your class
// so before use your class as usual need using needed namespace firstly 
using namespace A;
using namespace std;

int main(int argc, char **argv)
{
  // in cpp enhance the c struct to define func within struct directly
  // use class to replace struct to distinguish cpp enhance for the c struct
  cout << "use class to replace struct to distinguish cpp enhance for the c struct\n" << endl;
  Person per[2];
  per[0].setName("zhangsan");
  per[0].setAge(17);
  per[1].setName("lisi");
  per[1].setAge(18);
  int n;
  for(n=0; n<2; n++){
    per[n].print_func_cpp(n);
  }

  return 0;
}
