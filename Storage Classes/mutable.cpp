#include <iostream>
using namespace std;

class Demo {
    mutable int counter = 0;  // Can be modified even in const methods

public:
    void show() const {
        counter++;  // Allowed because counter is mutable
        cout << "Counter: " << counter << endl;
    }
};


int main() {
    Demo d;
    d.show();  // prints: Counter: 1
    d.show();  // prints: Counter: 2
}