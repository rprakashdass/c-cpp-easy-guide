#include <iostream>
using namespace std;

class Parent {
public:
    // Virtual function to enable run-time polymorphism
    virtual void display() {
        cout << "display called from Parent" << endl;
    }
};

class Child : public Parent {
public:
    // Override display() function in Child class
    void display() override {
        cout << "display called from Child" << endl;
    }
};

class Grandchild : public Parent {
public:
    // Override display() function in Grandchild class
    void display() override {
        cout << "display called from Grandchild" << endl;
    }
};

int main() {
    // Create objects of Parent, Child, and Grandchild
    Parent parent;
    Child child;
    Grandchild grandchild;

    // Call display() on each object directly
    cout << "Direct calls to display():" << endl;
    parent.display();
    child.display();
    grandchild.display();
    
    cout << "\nAfter implementing Runtime polymorphism:" << endl;

    // Create a Parent pointer to demonstrate run-time polymorphism
    Parent* parentPtr;

    // Point to Child object and call display()
    parentPtr = &child;
    parentPtr->display();

    // Point to Grandchild object and call display()
    parentPtr = &grandchild;
    parentPtr->display();

    return 0;
}
