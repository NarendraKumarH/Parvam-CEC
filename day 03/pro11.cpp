#include<iostream>
using namespace std;

class Student{
    public:
       int *marks;
       int size;
       Student(int s){
        size = s;
        marks = new int[size];
       }
       Student(const Student & s){
        size = s.size;
        marks = new int[size];
        for(int i = 0; i < size; i++){
            marks[i] = s.marks[i];
        }
       }
       ~Student(){
        delete[] marks;
       }
       void display(){
        for(int i = 0; i < size; i++){
            cout << marks[i] << " ";
        }
       }
};
int main(){
    Student s1(5);
    s1.marks[0] = 90;
    s1.marks[1] = 80;
    s1.marks[2] = 70;
    s1.marks[3] = 60;
    s1.marks[4] = 50;
    s1.display();
    Student s2(s1);
    s2.display();
    return 0;
}