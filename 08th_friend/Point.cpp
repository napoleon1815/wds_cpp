#include <iostream>
using namespace std;
class Point {
 private:
  int x;
  int y;
 public:
  Point(){}
  // x(x) for int x, y(y) for int y
  // the type of x is int, the same as private number int x
  // so call the copy constructor to make int x = x
  Point(int x, int y) : x(x), y(y) {}

  int getX() {return x;}
  int getY() {return y;}
  void setX(int x) {this->x = x;}
  void setY(int y) {this->y = y;}
  void printinfo()
  {
    cout << "(" << x << ", " << y << ")" << endl;
  }

  // define a function out of class, and use the key of friend to declare
  // the function which not belong this class to make the function can access
  // the private member of this class
  friend Point add(Point &p1, Point &p2);
};

Point add(Point &p1, Point &p2)
{
  Point n;
  n.setX(p1.getX() + p2.getX());
  n.setY(p1.getY() + p2.getY());
  //n.x = p1.x + p2.x;
  //n.y = p1.y + p2.y;
  return n;
}

int main(int argc, char **argv)
{
  Point p1(1,2);
  Point p2(2,3);

  Point sum = add(p1,p2);
  sum.printinfo();
  
  return 0;
}
