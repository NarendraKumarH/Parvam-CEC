#include<iostream>
using namespace std;

class Book
{
    public:
    string auther;
    string title;

    void display()
    {
        cout<< auther << "-"<< title <<endl;
    }
};

int main()
{
    Book b1;
    b1.auther = "Alice";
    b1.title = "C++";
    b1.display();
    return 0;
}