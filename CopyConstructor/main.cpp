#include <iostream>
using namespace std;

class Test{
    public:
        int x, y;
        
        Test(){
            cout << "Do nothing" << endl;
        }
        
        Test(const Test& obj){
            x = obj.x;
            y = obj.y;
            cout << "Copy constructor called x = " << ++x << " y = " << ++y << endl;
        }
        
        Test(int a, int b){
            x = a;
            y = b;
            cout <<"x = "<< x << endl << "y = " << y << endl;
            cout << "Parametrized constructor called x = " << x << " y = " << y << endl;
        }
        
        void display(){
            cout <<"x = "<< x << endl << "y = " << y << endl;
        }
};

int main()
{
    Test A(3,4);
    Test B(A);
    Test C;
    C = B;
    return 0;
}