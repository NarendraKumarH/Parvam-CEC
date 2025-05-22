#include<iostream>
using namespace std;

class DemoPrivate {
private:
    int secret;

public:
    void setSecret(int val) {
        secret = val;
    }

    void showSecret() {
        cout << "Secret: " << secret << endl;
    }
};

int main() {
    DemoPrivate obj;      
    obj.setSecret(10);       
    obj.showSecret();
    return 0;
}
