#include <iostream>
using namespace std;

class Human {
public:
  virtual void eating (void)
  {
    cout << "eat with hands" << endl;
  }
  ~Human ()
  {
    cout << "~Human()" << endl;
  }
};

class Englishman : public Human{
public:
  void eating (void)
  {
    cout << "eat with knife" << endl;
  }
  ~Englishman ()
  {
    cout << "~Englishman()" << endl;
  }
};

class Chinese : public Human {
public:
  void eating (void)
  {
    cout << "eat with chopsticks" << endl;
  }
  ~Chinese ()
  {
    cout << "~Chinese()" << endl;
  }
};

void test_eating (Human &h)
{
  Englishman *pe;
  Chinese *pc;
  
  h.eating();

  if (pe = dynamic_cast<Englishman *>(&h)) {
    cout << "this is human is englishman" << endl;
  }
  if (pc = dynamic_cast<Chinese *>(&h)) {
    cout << "this is human is chinese" << endl;
  }
}

int main(int argc, char **argv)
{
  Human a;
  Englishman b;
  Chinese c;
  cout << "sizeof(Human) = " << sizeof(Human) << endl;
  cout << "sizeof(Englishman) = " << sizeof(Englishman) << endl;
  test_eating(a);
  test_eating(b);
  test_eating(c);
  Human *d = new Human;
  Englishman *p = dynamic_cast<Englishman *>(d);
  cout << "orign a is Human" << endl;
  test_eating(*p);
  return 0;
}
