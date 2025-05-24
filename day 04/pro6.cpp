#include <iostream>
using namespace std;

class items
{
    private:
        string item;
        int cnt;

    public:
        int pr = 0, amt = 0;
        int setit(int c)
        {
            cnt = c;
        }
        
        void itm(string it, int cn)
        {
            if (it == "Mango")
            {
                pr = 10;
                amt = pr * cn;
                cout <<endl<< "You Ordered "<<cn << " "<<it;
            }

            else if (it == "Apple")
            {
                pr = 12;
                amt = pr * cn;
                cout << endl<<"You Ordered "<<cn << " "<<it;
            }

            else if (it == "Banana")
            {
                pr = 15;
                amt = pr * cn;
                cout << endl<<"You Ordered "<<cn << " "<<it;
            }

            else
            {
                cout << "We Do Not Have "<< it<<endl;
            }

        }

        int getamt()
        {
            return amt;
        }

        float disc()
        {
            float ds = 0.15;
            return ds;
        }

};

int main()
{
    float amt1,amt2,amt;
    items t1;


    t1.itm("Mango", 12);
    amt1 =t1.getamt();
    cout <<endl<<"Price :"<< amt1 <<endl;

    t1.itm("Banana", 24);
    amt2 = t1.getamt();
    cout <<endl<<"Price :"<< amt2<<endl;

    amt = amt1 + amt2;

    if(amt <= 500)
    {
        cout << "Before Discount : "<<amt<<endl;
        amt = amt - (amt*t1.disc());
        
        cout << "Discounted Price : "<<amt*t1.disc();
        cout <<endl<<"Total Price :"<< amt<<endl;
    }

    else
    {
        cout <<endl<<"Total Price :"<< amt<<endl;
    }


    return 0;
}