#include<iostream>
using namespace std;

class Mobile {
public:
    string brand;
    string model;
    float price;

    void showDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: ₹" << price << endl;
    }
};

int main() {
    Mobile m1;
    m1.brand = "I phone";
    m1.model = " 17 pro max ";
    m1.price = 189990;

    m1.showDetails();
    return 0;
}