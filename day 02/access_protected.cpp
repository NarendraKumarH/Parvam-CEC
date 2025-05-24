#include<iostream>
using namespace std;

class Base {
protected:
    int protVar;

public:
    void setProtVar(int val) {
        protVar = val;
    }
};

class Derived : public Base {
public:
    void showProtVar() {
        cout << "Accessed from Derived: " << protVar << endl; 
    }
};

int main() {
    Derived d;
    d.setProtVar(5);          
    d.showProtVar();
    return 0;
}