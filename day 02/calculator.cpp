#include <iostream>
using namespace std;

class Calculator{
    public:
    int add(int a, int b);
    int subtract(int a, int b);
};

int Calculator::add(int a, int b){
    return a + b;
}
int Calculator::subtract(int a,int b){
    return a - b;
}
int main(){
    Calculator calc;
    cout<<"Add:"<<calc.add(10,5)<<endl;
    cout<<"Subtract:"<<calc.subtract(10,5)<<endl;
    return 0;
}