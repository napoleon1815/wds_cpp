#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Person.h"
using namespace std;

namespace A {

void Person::setName(char *name)
{
  // by the princple of proximity, name is args rather than private data
  // use this to appoint to the member of class
  this->name = new char[strlen(name) + 1]; 
  strcpy(this->name, name);
  return;
}
int Person::setAge(int age)
{
  if (age < 0 || age >150){
    this->age = 0;
    return 0;
  } else {
    this->age = age;
    return 1;
  }
}
// within cpp, can define function and use member in the body of func directly
void Person::print_func_cpp(int k)
{
  printf("name%d %s, age%d %d\n", k+1, name, k+1, age);

  return;
}

}
