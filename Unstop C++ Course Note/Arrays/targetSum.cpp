/******************************************************************************
all possible subsequences
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void recur(int i, int n, int sum, int k, vector<int>& ipt, vector<int>& opt) {
    if (i == n) {
        if(sum == k){
            for(int a: opt)
                cout << a << " ";
            cout << endl;
        }
        return;
    }
    
    opt.push_back(ipt[i]);
    sum += ipt[i];
    recur(i + 1, n, sum, k, ipt, opt);
    
    opt.pop_back();
    sum -= ipt[i];
    recur(i + 1, n, sum, k, ipt, opt);
}

int main() {
    vector<int> ipt;
    ipt = {3, 1, -1, 2, 5};
    vector<int> opt;
    // int sum = 3;
    recur(0, 5, 0, 3, ipt, opt);
    return 0;
}

/*
TC->2^n
SC->O(1)
*/
