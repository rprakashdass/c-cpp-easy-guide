#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m.insert(make_pair("ram", 2));
    m.insert(make_pair("avi", 4));
    m.insert(make_pair("ravi", 3));
    for(auto it = m.begin(); it != m.end(); it++){
        cout << "key is " << it->first << " ";
        cout << "value is " << it->second << endl;
    }
    auto it = m.find("avi");
    if( it == m.end())
        cout << "not ";
    else
        cout << it->first;
    return 0;
}