#include <iostream>
using namespace std;

class Person
{
private:
      string name;
      int age;
   
  public:
      void  setData(string n, int a)
{
     name = n;
     age = a;
}
void displayData()
{
    cout<< "Name: " << name << " , Age: " << age << endl;
}
};
int main() {
            Person p1;
            p1.setData("Narendra",20);
            p1.displayData();
            return 0;

}