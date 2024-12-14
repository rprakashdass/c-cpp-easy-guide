#include <iostream>
using namespace std;

// Binary operator overloading allows custom behavior for binary operators (e.g., +, -, *, /)
// for user-defined types, making them behave intuitively.

class IntegerTest {
    int a, b;

public:
    // Constructor to initialize the members a and b
    IntegerTest(int a = 1, int b = 1) : a(a), b(b) {}

    // Overloading the binary + operator
    IntegerTest operator+(IntegerTest obj) {
        // Combine the values of the current object and the passed object
        obj.a = a + 200;
        obj.b = b + 200;
        return obj; // Return the modified object
    }

    // Function to display the values of the object
    void display() {
        cout << "a = " << a << "\nb = " << b << endl;
    }
};

int main() {
    // Creating two IntegerTest objects with default values (a = 1, b = 1)
    IntegerTest obj1;
    IntegerTest obj2;

    // Displaying initial values of obj1 and obj2
    cout << "Initial values of obj1:" << endl;
    obj1.display();
    cout << "Initial values of obj2:" << endl;
    obj2.display();

    // Using the overloaded + operator to add obj1 and obj2
    // This calls the operator+ function of obj1, passing obj2 as an argument
    IntegerTest res = obj1 + obj2;

    // Displaying the result of the addition
    cout << "\nAfter using the overloaded + operator (obj1 + obj2):" << endl;
    res.display();

    return 0;
}
