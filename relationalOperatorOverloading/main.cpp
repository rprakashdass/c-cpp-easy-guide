#include <iostream>
using namespace std;

class Student {
public:
    int height, weight;

    // Constructor to initialize height and weight
    Student(int h = 0, int w = 0) : height(h), weight(w) {}

    // Overload the > operator
    bool operator>(const Student& obj) const {
        return height > obj.height;
    }

    // Overload the >= operator
    bool operator>=(const Student& obj) const {
        return height >= obj.height;
    }

    // Overload the < operator
    bool operator<(const Student& obj) const {
        return height < obj.height;
    }

    // Overload the <= operator
    bool operator<=(const Student& obj) const {
        return height <= obj.height;
    }

    // Overload the == operator
    bool operator==(const Student& obj) const {
        return height == obj.height && weight == obj.weight;
    }
};

int main() {
    Student obj1(120, 50);
    Student obj2(75, 50);

    // Compare using >
    bool greaterThan = obj1 > obj2;
    cout << "obj1 > obj2: " << greaterThan << endl;

    // Compare using >=
    bool greaterThanOrEqual = obj1 >= obj2;
    cout << "obj1 >= obj2: " << greaterThanOrEqual << endl;

    // Compare using <
    bool lessThan = obj1 < obj2;
    cout << "obj1 < obj2: " << lessThan << endl;

    // Compare using <=
    bool lessThanOrEqual = obj1 <= obj2;
    cout << "obj1 <= obj2: " << lessThanOrEqual << endl;

    // Compare using ==
    bool equalTo = obj1 == obj2;
    cout << "obj1 == obj2: " << equalTo << endl;

    return 0;
}
