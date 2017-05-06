#include <iostream>
using namespace std;

class Furniture {
private:
  int weight;
public:
  void setWeight(int weight) {this->weight = weight;}
  int getWeight(void) {return weight;}
};

// use virtual iheritance to eliminate the same member defined in multiple class
// defined the same member into a base class uniformly
// and use virtual inherit in derived class
// so the same member will store in the object of base class
// rather than multiple objects of multiple derived class
class Soft : virtual public Furniture {
public:
  void watchTV (void) {cout << "watch TV" << endl;}
};

class Bed : virtual public Furniture {
public:
  void sleep (void) {cout << "sleep" << endl;}
};

class Soft_bed : public Soft, public Bed {
};

int main(int argc, char **argv)
{
  Soft_bed a;
  a.watchTV();
  a.sleep();
  a.setWeight(100);
  cout << "soft bed weight = " << a.getWeight() << endl;
}
