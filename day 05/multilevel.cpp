#include <iostream>
using namespace std;

class Animal
{
    public:
    void breathe()
    {
        cout << "Animal is breathing..." << endl;
        }
};
class Mammal : public Animal
{
    public:
    void feedMilk()
    {
        cout << "Mammal is feeding milk to babies.." << endl;
    }
};

class Dog : public Mammal
{
    public:
    void bark()
    {
        cout << "Dog is barking..." <<endl;
    }
};
 
int main()
{
    Dog d;
    d.breathe();
    d.feedMilk();
    d.bark();
    return 0;
}