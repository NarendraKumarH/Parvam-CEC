#include <iostream>
using namespace std;
class Student
{
    public:
    string name;
    int age;
    int usn;
    string college;
    Student (string n, int a , int b , string c)
    {
        name = n;
        age = a;
        usn = b;
        college = c;
         cout << "Name: " << name << " Age: " << age << " USN: " << usn << " College: " << college << endl;
    }
};
int main()
{
    Student s1("Narendra" ,19 , 146536 , " City engineering college ");
    Student s2("Sri hari" ,19 , 555688 , " PES university ");
    Student s3("Dhanush"  ,19 , 778669 , " Jain university ");
            return 0;
}