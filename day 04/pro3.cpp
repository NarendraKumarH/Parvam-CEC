#include<iostream>
using namespace std;

class user 
{
    private:
        int cardnum;
        int pin;
        double balance;

    public:
    user(int cardnum, int pin, double balance)
    {
        cardnum = cardnum;
        pin = pin;
        balance = balance;
    }
    bool authenticate(int entered_pin, int entered_cardnum)
    {
        return (pin == entered_pin && cardnum == entered_cardnum);
    }
    bool withdraw(int entered_pin, int entered_cardnum, double amount)
    {
        if (authenticate(entered_pin, entered_cardnum))
        {
            if (amount <= balance)
            {
                balance -= amount;
                cout << "Withdrawal successful! New balance: " << balance << endl;
                return true;
            }
            else
            {
                cout << "Insufficient funds!" << endl;
                return false;
            }
        }
        else
        {
            cout << "Authentication failed!" << endl;
            return false;
        }
    }
    };

int main()
{
    user u1(123456789, 1234, 10000);
    user u2(987654321, 5678, 20000);

    int entered_pin, entered_cardnum;
    double amount;

    cout << "Enter card number: ";
    cin >> entered_cardnum;
    cout << "Enter pin: ";
    cin >> entered_pin;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    u1.withdraw(entered_pin, entered_cardnum, amount);
    u2.withdraw(entered_pin, entered_cardnum, amount);

    return 0;
}