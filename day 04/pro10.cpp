#include <iostream>
using namespace std;

class Payment
{
    public:
    virtual ~Payment() {}

    virtual void pay() = 0;
};

class CreditedPayment : public Payment
{public:
    void pay() override
    {
      cout << "Processing credit card payment..."<< endl;
    }

};

class PayPalPayment : public Payment
{
    public:
     void pay() override
     {
        cout <<"Proccessing PayPal payment..." <<endl;
     }
};
int main()
{
    Payment *paymentMethod =nullptr;
    int choice;

    cout << "Choose a payment method:\n";
    cout << "1. Credit Card\n";
    cout << "2. PayPal\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    switch (choice)
    {
        case 1:
        paymentMethod = new CreditedPayment(); 
        cout<<" 5000 to 10000\t";
        break;
        case 2:
        paymentMethod = new PayPalPayment();
        cout<<" 20000 to 30000\t";
        break;
        default:

        cout << "Invalid choice.  Exiting..." <<endl;
        return 1;
    }
    paymentMethod-> pay();

    delete paymentMethod;
    return 0;
};
