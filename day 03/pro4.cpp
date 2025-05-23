#include<iostream>
using namespace std;

class car {
    string model;
    int year;

public:
  car(){
    model = "Unknown";
    year = 0;
  }

  car(string m){
    model = m;
    year = 0;
  }

  car(string m, int y){
    model = m;
    year = y;
  }

  void display(){
    cout << "Model: " << model << "Year:" << year << endl;
  }
};

int main(){
    car c1;
    car c2("Toyota");
    car c3("Honda", 2015);
    
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
