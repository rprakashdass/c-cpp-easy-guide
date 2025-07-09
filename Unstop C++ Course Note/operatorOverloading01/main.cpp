#include <iostream>
using namespace std;

class Test {
    int x, y, z;

public:
    Test(int x = 1, int y = 1, int z = 1) : x(x), y(y), z(z) {}

    // Overload the unary + operator
    void operator+() {
        x--;
        y--;
        z--;
    }

    // Overload the binary + operator
    Test operator+(const Test& other) {
        return Test(x + other.x, y + other.y, z + other.z);
    }

    // Without friend, the function would not be able to access the private members 
    // Overload the << operator for outputting the object
    friend ostream& operator<<(ostream& os, const Test& obj) {
        os << "x = " << obj.x << "\ny = " << obj.y << "\nz = " << obj.z << endl;
        return os;
    }

    void display() {
        cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
    }
};

int main() {
    Test obj1(2, 3, 4);
    Test obj2(5, 6, 7);

    cout << "Initial values of obj1:" << endl;
    obj1.display();

    cout << "Initial values of obj2:" << endl;
    obj2.display();

    // Using the overloaded unary + operator
    +obj1;

    cout << "\nAfter using unary + operator on obj1:" << endl;
    obj1.display();

    // Using the overloaded binary + operator
    Test obj3 = obj1 + obj2;

    cout << "\nAfter using binary + operator (obj1 + obj2):" << endl;
    obj3.display();

    // Using the overloaded << operator
    cout << "\nUsing overloaded << operator:" << endl;
    cout << obj3;

    return 0;
}
