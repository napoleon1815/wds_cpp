namespace A {

// use the class name to define a couple of .cpp & .h files to define the class
// so if the fist charater is high-char can easily recongize it used for define a class
class Person{
private: // the default access control of class is private
         // which means it only can be accessed within class
  char *name;
  int age;
public: // the public of access control means it can be accessed out ot class 
  // define public function to operate private data
  // to avoid user wrong operate on private data
  void setName(char *name);
  int setAge(int age);
  // within cpp, can define function and use member in the body within class directly
  // if the body is short, define function in class
  // else declare function in .h file of class and define in .cpp file of class
  void print_func_cpp(int k);
};

}
