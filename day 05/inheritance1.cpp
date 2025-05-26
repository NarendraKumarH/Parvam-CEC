#include <iostream>
using namespace std;

class Vehicle
{
    public:
    void start()
    {
        cout <<"Vehicle has stoped." <<endl;
    }
};
class Car : public Vehicle
{ 
    public:
    void drive()
    {
            cout << " Car is stoping at the resturant for lunch." <<endl;

    }
};
int main()
{
    Car myCar;
    myCar.start();
    myCar.drive();
    return 0;
}
