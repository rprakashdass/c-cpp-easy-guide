/*
----------------------
DeQueue
---------------------

  ->Doubly Ended queue
  ->insertion & deletion at both sides
  ->Dynamic Data Structure

--------------------
Most Common Methods
---------------------

 => operator[] - to access
 => push_front() - add element at start
 => push_back() - add element at end
 => pop_front() - delete element at start
 => push_back() - delete element at end
 =>d.front() - return front
 => d.back() - returns back
 =>d.size() - returns size
 => d.erase(i) - to erase ith element

*/



#include <iostream>
#include<deque>
using namespace std;

int main()
{
    // doubly ended queue
    deque<int> v;
    v.push_back(11);
    v.push_front(10);
    v.push_front(0);
    v.push_back(20);
    v.push_front(100);
    for(int i = 0;i < 5;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    v.pop_front();
    v.pop_back();
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    return 0;
}