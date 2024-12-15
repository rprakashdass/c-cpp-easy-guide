/******************************************************************************
all possible subsequences
*******************************************************************************/
#include <iostream>
#include <array>
#include <string>
using namespace std;

void recur(array<int, 3>& ar, int i, int n, string& s) {
    if (i == n) {
        if (!s.empty()) {
            cout << s << endl;
        } else {
            cout << "{}" << endl;
        }
        return;
    }
    
    // Include the current element
    string temp = to_string(ar[i]) + " ";
    s += temp;
    recur(ar, i + 1, n, s);
    
    // Exclude the current element (backtrack)
    s.erase(s.size() - temp.size(), temp.size());
    recur(ar, i + 1, n, s);
}

int main() {
    array<int, 3> ar = {3, 1, 2};
    string s = "";
    recur(ar, 0, 3, s);
    return 0;
}

/*
TC->2^n
SC->O(N)
OUTPUT:
3 1 2 
3 1 
3 2 
3 
1 2 
1 
2 
{}
*/
