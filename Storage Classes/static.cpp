#include<iostream>
using namespace std;

static int globalVar = 9;

// here number is only accessable from counter but initialization happen only once even we call counter function manytime
void counter() {
    static int number = 10;
    cout << ++number << endl;
}

void print() {
    cout << "In print: " << globalVar << endl;
    globalVar *= 10;
}

int main() {
    // static inside functions
    for(int i = 0;i < 10;i++) {
        counter();
    }

    cout << "static Global Var\n";

    cout << globalVar << endl;
    globalVar += 10;

    cout << "In main: " << globalVar << endl;
    print();
    cout << globalVar << endl;
}