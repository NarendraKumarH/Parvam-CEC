#include<iostream>
using namespace std;

class ClassStudent{
    public:
        string name;
        int marks;

        ClassStudent(){
            name="Narendra";
            marks=600;
            cout << "Default Constructor Called." << endl;
        }
        
        void drive(){
            cout << " Name: " << name << " Marks:  " << marks << endl;
        }
};  

int main(){
    ClassStudent c1;
    c1.drive();
    return 0;
}