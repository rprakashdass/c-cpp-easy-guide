#include <iostream>
using namespace std;

class Test{
    public:
        int obj_id = 0;
        Test(){
            cout << "Constructor called for " << obj_id << endl;
        }
        ~Test(){
            cout << "destructor called for " << obj_id << endl;
        }
};


int main()
{
    Test obj1;
    obj1.obj_id = 1;
    if(1){
        Test obj2;
        obj2.obj_id = 2;
        if(1){
            Test obj3;
            obj3.obj_id = 3;
        }
    }
    return 0;
}