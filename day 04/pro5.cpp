#include <iostream>
using namespace std;

class Product
{
    private:
    int quantity;
    float pricePerItem;
public:
void setProduct(int q, float price)
{
    if (q > 0 && price > 0)
    {
        quantity = q;
        pricePerItem = price;
    }
    else{
        cout << "Invalid quantity or price!"<< endl;
    }
}
float getTotalPrice()
{
    return quantity * pricePerItem;
}
int getQuantity()
{
    return quantity;
}
float getUnitPrice()
{
    return pricePerItem;
}
};

int main()
{
    Product item1;

    item1.setProduct(3, 499.99);

    cout <<"Item Bought:  "<< item1.getQuantity()<<endl;
    cout <<"Price per Item: $"<< item1.getUnitPrice()<<endl;
    cout <<"Total Cost:  $"<< item1.getTotalPrice() <<endl;
    
    return 0;


}

