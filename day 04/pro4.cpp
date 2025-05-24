#include <iostream>
using namespace std;

class Student
{
private:
    int rollNumber;
 
public:

    void setRollNumber(int r)
{
        rollNumber = r;
}


int getRollNumber()
{
        return rollNumber;
}
};
int main(){
    Student s1;
    s1.setRollNumber(111);
    cout<< s1.getRollNumber()<< endl;

    return 0;

}