#include <iostream>
using namespace std;

class Test {
public:
    int a, b;
    
    // Parameterized constructor
    Test(int a, int b) : a(a), b(b) {
        cout << "Parameterized constructor called with a = " << a << ", b = " << b << endl;
    }
    
    // Conversion constructor (takes a single argument)
    Test(int x) : a(x), b(0) {
        cout << "Conversion constructor called with x = " << x << endl;
    }
    
    // Method to display values
    void display() const {
        cout << "a = " << a << ", b = " << b << endl;
    }
};

int main() {
    // Using parameterized constructor
    Test obj1(10, 20);
    obj1.display();
    
    // Using conversion constructor (implicit conversion from int)
    Test obj2 = 30;
    obj2.display();
    
    // Conversion constructor can also be used directly
    Test obj3(40); // Implicit conversion
    obj3.display();

    // Conversion constructor can also be used directly
    Test obj4 = {40,50}; // Implicit conversion
    obj4.display();
    
    return 0;
}
