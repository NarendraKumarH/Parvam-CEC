#include <iostream>
using namespace std;

class Item 
{
    private:
    int quantity;
    float price;
    public:
    Item( int q = 0, float p = 0.0f) : quantity(q), price(p) {}

    Item operator+(const Item &other) 
    {
        return Item(quantity + other.quantity, price + other.price);
    }
    bool operator==(const Item &other)
    {
        return (quantity == other.quantity && price == other.price);
    }
    friend ostream &operator<<( ostream &os, const Item &item)
    {
        os << "Item -> Quantity: " << item.quantity << ", Price: " << item.price;
        return os;
    }
};
int main()
{
    Item item1(10, 250.50);
    Item item2(5, 100.25);
    Item item3(10, 250.50);

    Item  total = item1 + item2;

    cout << total << endl;

    if (item1 == item3)
    cout << "Item1 and Item3 are same in quantity and price." << endl;
    else
    cout << "Item1 and Item3 are not different." << endl;
    return 0;
}