#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int val,n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        cin >> val;
        a.push_back(val);
    }
    int q,find;
    cin >> q;
    while(q!=0)
    {
        cin >> find;
        vector<int>::iterator low;
        low=std::lower_bound (a.begin(), a.end(), find);
        if(a[low-a.begin()]==find)
        {
            cout << "Yes " << (low-a.begin()+1) << endl;
        } 
        else {
        cout << "No " << (low-a.begin()+1) << endl;
        }
        q--;
    }          
    return 0;
}
