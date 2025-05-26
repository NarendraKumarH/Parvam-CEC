#include <iostream>
using namespace std;

class User
{
    public:
    string name, email;
    void login()
    {
        cout << name << " logged in with email " << email << endl;
    }
};
class Customer: public User{
    public:
    void browseProducts() 
    {
        cout << name << " is browsing products." <<endl;
    }
};
int main()
{
    Customer c;
    c.name ="Narendra";
    c.email = "chinnu8775@gmail.com";
    c.login();
    c.browseProducts();
    return 0;

}