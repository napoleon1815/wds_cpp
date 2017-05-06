#include <iostream>
using namespace std;
class Point {
 private:
  int x;
  int y;
 public:
  Point()
  {
    cout << "Point()\n" << endl;
  }
  // x(x) for int x, y(y) for int y
  // the type of x is int, the same as private number int x
  // so call the copy constructor to make int x = x
  Point(int x, int y) : x(x), y(y)
  {
    cout << "Point(int x, int y)\n" << endl;
  }
  Point(const Point& p)
  {
    cout << "Point(Point &p)\n" << endl;
    x = p.x;
    y = p.y;
  }
  ~Point()
  {
    cout << "~Point()\n" << endl;
  }

  int getX() {return x;}
  int getY() {return y;}
  void setX(int x) {this->x = x;}
  void setY(int y) {this->y = y;}
  void printinfo()
  {
    cout << "(" << x << ", " << y << ")";
  }
  // define in class to reduce a args by using private data
  //Point operator+(Point &p2)
  //{
  //  Point n;
  //  this->x = this->x + p2.x;
  //  this->y = this->y + p2.y;
  //  return n;
  //}
  //Point& operator++()
  //{
  //  cout << "++p\n" << endl;
  //  this->x = this->x + 1;
  //  this->y = this->y + 1;
  //  return *this;
  //}
  //Point operator++(int a)
  //{
  //  cout << "p++\n" << endl;
  //  Point p = *this;
  //  this->x = this->x + 1;
  //  this->y = this->y + 1;
  //  return p;
  //}
  // define a function out of class, and use the key of friend to declare
  // the function which not belong this class to make the function can access
  // the private member of this class
  friend Point operator+(Point &p1, Point &p2);
  friend Point& operator++(Point &n);
  friend Point operator++(Point &n, int a);
  friend ostream& operator<<(ostream& o, Point p);
};

Point add(Point &p1, Point &p2)
{
  Point n;
  n.setX(p1.getX() + p2.getX());
  n.setY(p1.getY() + p2.getY());
  return n;
}

// a operator is also a function, so it also can be overload
// take operator operator_name as the name of operator function and overload it
Point operator+(Point &p1, Point &p2)
{
  Point n;
  n.x = p1.x + p2.x;
  n.y = p1.y + p2.y;
  return n;
}

// ++p
// b = ++a; => a = a + 1; b = a;
// the type of function is & to avoid return call constructor instant object again
// so return & to increase efficiency
Point& operator++(Point &n)
{
  cout << "++p\n" << endl;
  n.x = n.x + 1;
  n.y = n.y + 1;
  return n;
}

// p++
// b = a++; => b = a; a = a + 1;
// c++ rules: for ++ use int is p++, no int is ++p
// so add int to distinguish with ++p
// need return an temp object to store original value no & args can be used
// so need return object
Point operator++(Point &n, int a)
{
  cout << "p++\n" << endl;
  Point p;
  p = n;
  n.x = n.x + 1;
  n.y = n.y + 1;
  return p;
}

ostream& operator<<(ostream& o, Point p)
{
  cout << "(" << p.x << " " << p.y << ")";
  return o;
}

int main(int argc, char **argv)
{
  Point p1(1,2);
  Point p2(2,3);

  Point sum1 = add(p1,p2);
  sum1.printinfo();
  
  Point sum2 = p1 + p2;
  sum2.printinfo();

  cout << "***************" << endl;
  p1.printinfo();
  Point m = p1++;
  m.printinfo();
  p1.printinfo();
  cout << "***************" << endl;
  p2.printinfo();
  Point n = ++p2;
  n.printinfo();
  p2.printinfo();
  
  Point o(1, 2);
  cout << "begin\n" << endl;
  o++;
  cout << "***************" << endl;
  ++o;
  cout << "end" << endl;

  cout << m << " " << n << endl;

  
  return 0;
}
