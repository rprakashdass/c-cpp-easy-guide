#include <iostream>
using namespace std;

// Abstract base class with a pure virtual function
class Shape {
public:
    // Pure virtual function to be overridden by derived classes
    virtual void draw() = 0;

    // Virtual function that can be overridden but is not pure
    virtual void move() {
        cout << "Moving the shape" << endl;
    }

    // Non-virtual function
    void info() {
        cout << "This is a shape" << endl;
    }
};

// Derived class overriding the pure virtual function
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }

    void move() override {
        cout << "Moving the Circle" << endl;
    }
};

// Another derived class overriding the pure virtual function
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }

    // Uses the base class implementation of move()
};

// Another derived class with additional functionalities
class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Triangle" << endl;
    }

    void move() override {
        cout << "Moving the Triangle" << endl;
    }

    // Additional function unique to Triangle
    void calculateArea() {
        cout << "Calculating the area of the Triangle" << endl;
    }
};

int main() {
    // Shape shape; // This will cause a compile-time error as Shape is an abstract class

    // Pointers to the base class can be used to point to derived class objects
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();
    Shape* shape3 = new Triangle();

    // Calling overridden functions through base class pointers
    shape1->draw();
    shape1->move();
    shape1->info();

    shape2->draw();
    shape2->move(); // Calls the base class implementation of move()
    shape2->info();

    shape3->draw();
    shape3->move();
    shape3->info();

    // Cleanup
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
