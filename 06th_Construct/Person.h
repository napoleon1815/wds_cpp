#include <iostream>
#include <string.h>
using namespace std;

namespace A {

// use the class name to define a couple of .cpp & .h files to define the class
// so if the fist charater is high-char can easily recongize it used for define a class
class Person{
private: // the default access control of class is private
         // which means it only can be accessed within class
  char *name;
  int age;
public: // the public of access control means it can be accessed out ot class 

  // for every class will default provide three functions 
  // constructor & destructor & copy constructor for easy assignment when initialization
  // default the body of constructor & destructor are all emptry
  // and copy constructor is defined for value copy

  // constructor(it will call destructor autoly)
  // 1. the name of construct is same as class
  // 2. maybe has args or not, but no return type
  // 3. it supports overload, so one class can have more constructs  
  // 4. it called by
  // 1) class value
  //    args transfered by value(), if no args value no use ()
  //    to distinguish function declare
  //    type transfered by function(), if no args use function()
  //    it will call destructor autoly
  //    when the scope of define object(class value) ended up
  // 2) new class(need delete manuanly)
  //    new is easier to use than array, no need array name, just use ptr
  //    args transfered by class(), if no args class can use () or not
  //    so can use class[array_number] to call no args
  // 5. the order of calling constructor by the order of private member,
  //    finally is the class itself
  // 6. if define a parametric constructor, the default nonparametric constructor
  //    will become invalid, so must define a nonparametric constructor
  Person()
  {
    cout<<"Person()"<<endl;
    this->name = new char[1];
  }
  Person(char *name, int age)
  {
    cout<<"Person(char *, int) name=" << name << "," << "age=" << age << "\n" << endl;
    //printf("Person(char *, int) name=%s, age=%d\n",name,age);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
  }
  // copy constructor
  // the default copy constructor will copy the value of the member value of args object
  // so the two memory address of objects member value is same
  // it will occur destructor free same address twice
  // need copy pointer value manuanly
  Person(Person &per)
  {
    cout<<"Person(Person &)"<<endl;
    this->name = new char[strlen(per.name) + 1];
    strcpy(this->name, per.name);
    this->age = per.age;
  }
  // destructor
  // 1. the name of destructor is the name of ~class
  // 2. and has no args and not support overload
  // 3. destructor will do for every constructor including nonparametric constructor
  //    it called by the scope of define object(class value) ended up
  // 4. the order of calling destructor contrary to the order of constructor
  ~Person()
  {
    if (this->name) {
      cout << "~Person() name = " << name << "\n" << endl;
      delete this->name;
    }
  }

  // define public function to operate private data
  // to avoid user wrong operate on private data
  void setName(char *name);
  int setAge(int age);
  // within cpp, can define function and use member in the body within class directly
  // if the body is short, define function in class
  // else declare function in .h file of class and define in .cpp file of class
  void print_func_cpp(int k);
};

 class Student {
 private:
   Person father;
   Person monther;
   int student_id;
 public:
   // call the constructor of Person()
   Student()
   {
     cout << "Student()" << endl;
   }
   // call the constructor of Person(char *, int)
   // the args of Person(member class) must define in Student(the class own the member)
   // and the order of calling constructor by the order of private member,
   // finally is the class itself, have nothing to do with the order of : content
   Student(int student_id, char *fa, char *mo, int fa_i, int mo_i):father(fa, fa_i), monther(mo, mo_i)
   {
     cout << "Student(int, char*, char*, int, int)\n" << endl;
   }
   ~Student()
   {
     cout << "~Student()" << endl;
   }
 }; 
}
