#include<iostream>
using namespace std;

// single

class A{
    public:
        char className = 'A';
};

class B{
    public:
        string className = "A singly inherited ";
};

// multiple

class C: public A, public B, public C{
    // 
}

// multiple level


// hybrid


// hierarchy

int main(){
    A a;
    B b;
    cout << a.className;
    cout << b.className;
}