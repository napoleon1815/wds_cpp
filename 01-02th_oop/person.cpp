#include <stdio.h>

void print_func(char *name, int age, int k)
{
  printf("name%d %s, age%d %d\n", k+1, name, k+1, age);

  return;
}

struct person {
  char *name;
  int age;
  // define the pointer of function just like the declartion and add a * before func_name
  void (*print_func)(char *name, int age, int j);

  // within cpp, can define function and use member in the body of func directly
  void print_func_cpp(int k)
  {
    printf("name%d %s, age%d %d\n", k+1, name, k+1, age);
    return;
  }
};
// within cpp no need use typedef to define type
typedef struct person ps;

class Person_class {
private: // the default access control of class is private
         // which means it only can be accessed within class
  char *name;
  int age;
public: // the public of access control means it can be accessed out ot class 
  // define public function to operate private data
  // to avoid user wrong operate on private data
  void setName(char *name)
  {
    // by the princple of proximity, name is args rather than private data
    // use this to appoint to the member of class
    this->name = name; 
    return;
  }
  int setAge(int age)
  {
    if (age < 0 || age >150){
      this->age = 0;
      return 0;
    } else {
      this->age = a;
      return 1;
    }
  }
  // within cpp, can define function and use member in the body of func directly
  void print_func_cpp(int k)
  {
    printf("name%d %s, age%d %d\n", k+1, name, k+1, age);

    return;
  }
};
typedef class Person_class ps_class;

int main(int argc, char **argv)
{
  // use variable to store data
  char *name1 = "zhangsan";
  char *name2 = "lisi";

  int age1 = 17;
  int age2 = 18;

  printf("use variable to store data\n");
  printf("name1 %s, age1 %d\n",name1,age1);
  printf("name2 %s, age2 %d\n",name2,age2);
  printf("\n");

  // use array & loop to store large data
  char *names[] = {"zhangsan", "lisi"};
  int ages[] = {17, 18};
  printf("use array & loop for large data\n");
  int i;
  for(i=0;i<2;i++){
    printf("name%d %s, age%d %d\n", i+1, names[i], i+1, ages[i]);
  }
  printf("\n");
  
  // use structure to enstablish associated multiple arrays
  ps persons[] = {
    {"zhangsan", 17, print_func},
    {"lisi", 18, print_func},
  };
  printf("use structure to enstablish associated multiple arrays\n");
  int j;
  for(j=0;j<2;j++){
    printf("name%d %s, age%d %d\n", j+1, persons[j].name, j+1, persons[j].age);
  }
  printf("\n");

  // add operaton function for the structure within struct 
  printf("add operaton function for the structure within struct\n");
  int k;
  for(k=0; k<2; k++){
    persons[k].print_func_cpp(k);
  }
  printf("\n");

  // the pointer of function can not establish a connection
  // between func and member within structure
  // so use the function to operate member is really troublesome
  // use the structure of cpp to imply this request briefly 
  printf("use the structure of cpp to imply this request briefly\n");
  int m;
  for(m=0; m<2; m++){
    persons[m].print_func_cpp(m);
  }
  printf("\n");

  // in cpp enhance the c struct to define func within struct directly
  // use class to replace struct to distinguish cpp enhance for the c struct
  printf("use class to replace struct to distinguish cpp enhance for the c struct\n");
  Person_class per[2];
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
