#include<stdio.h>

int main(int argc, char **argv)
{
  double d = 100.1;
  int i = d;
  const char *str1 = "Hello World\n";
  char * str2 = const_cast<char *>(str1);
  int *p = reinterpret_cast<int *>(str2);
  // error: cast from ‘char*’ to ‘unsigned int’ loses precision [-fpermissive]
  // need use cmd: g++ covert.cpp -o covert -fpermissive 
  printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str2), reinterpret_cast<unsigned int>(p));
  return 0;
}
