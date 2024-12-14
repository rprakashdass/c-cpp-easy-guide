#include <iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> v;
    v.push_front(90);
    v.push_front(10000);
    v.push_front(100);

    // push_back wont work, emplace_front() will work
    // pop_back does'nt work
    // Cant access elements with [] operator

    cout << endl;
    v.pop_front();
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // sort will work
    v.sort();    
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // reverse will also work
    v.reverse();    
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // remove will also work erase() does'nt work
    v.remove(90);    
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    return 0;
}