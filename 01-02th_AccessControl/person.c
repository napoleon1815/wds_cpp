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
};
typedef struct person ps;

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
    persons[k].print_func(persons[k].name, persons[k].age, k);
  }
  printf("\n");

  return 0;
}
