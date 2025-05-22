#include<iostream>
using namespace std;

class Car{
    public:
    string brand;
    void start(){
        cout<<brand<<" car started"<<endl;

    }
};

int main(){
    Car c1,c2,c3;

    c1.brand="Toyata fortuner";
    c2.brand="BMW";
    c3.brand="Ferrari";
    c1.start();
    c2.start();
    c3.start();
    return 0;
}