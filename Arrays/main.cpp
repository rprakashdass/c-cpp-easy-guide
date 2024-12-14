#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> ar = {1,3,5,7,9};
    array<int, 5> arr = {2,4,6,8,10};
    
    cout << "Before change" << endl;
    for(const int& i: ar){
        cout << i << " ";
    }
    cout << endl;
    
    // array.front()
    cout << "First element is " << ar.front() << endl;
    // array.back()
    cout << "Last element is " << ar.back() << endl;
    
    // array.fill()
    
    ar.fill(3);
    cout << "arr.fill(3)" << endl;
    for(const int& i: ar){
        cout << i << " ";
    }
    cout << endl;
    
    // array.swap()
    
    ar.swap(arr);
    cout << "ar.swap(arr)" << endl;
    for(const int& i: ar){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}