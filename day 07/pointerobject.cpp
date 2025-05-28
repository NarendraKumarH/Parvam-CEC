#include <iostream>
using namespace std;

 class Dog
 {
    public:
    void bark()
    {
        cout << "Woof!" << endl;
    }
 };

 int main()
 {
    Dog *d = new Dog();
    d->bark();
    delete d;
    return 0;

 }


