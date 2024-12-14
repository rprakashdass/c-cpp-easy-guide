#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

int print(int n){
    return n;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<int, std::function<int(int)>> m;
    m.insert({1, print});
    // for(auto itr = m.begin(); itr != m.end(); ++itr){
    //     cout << itr->first << " " << itr->second(7) << endl;
    // }
    cout << m[1] << " ";
    return 0;
}