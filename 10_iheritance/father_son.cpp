#include <iostream>
#include <string.h>
using namespace std;

class Father{
private: // only can be accessed in defined class
  int money;
  char *name;
protected: // except for the defined class, can be accessed by the class of inheritors
  int room_key;
public: // can be accessed out of class
  void setName(char *name)
  {
    this->name = name;
  }
  char * getName(void)
  {
    return name;
  }
  void it_skill(void)
  {
    cout << "father's it skill" << endl;
  }
  int getMoney(void)
  {
    return money;
  }
  void setMoney(int money)
  {
    this->money = money;
    return;
  }
  void printInfo(void)
  {
    cout << "father" << endl;
  }
};

class Son : public Father{
private:
  int toy;
  char *name;
public:
  using Father::room_key;
  void setName(char *name)
  {
    this->name = name;
  }
  char * getName(void)
  {
    return name;
  }
  void play_game(void)
  {
    cout << "son's play game" << endl;
    // access & modify Father's private data
    int m = getMoney();
    m--;
    setMoney(m);
  }
  int getRoomKey(void)
  {
    return room_key;
  }
  void printInfo(void)
  {
    cout << "son" << endl;
  }
};

void test_func(Father &p)
{
  p.printInfo();
  return;
}

int main(int argc, char **argv)
{
  Son s;
  s.setName("son");
  s.play_game();
  s.it_skill();
  s.setMoney(100);
  cout << "father's money = " << s.getMoney() << endl;
  test_func(s);
  cout << "name = " << s.getName() << endl;
  return 0;
}
