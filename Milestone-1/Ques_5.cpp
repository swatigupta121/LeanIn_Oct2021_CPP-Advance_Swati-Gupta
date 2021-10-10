#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char name[50];
    map<string,int> m;
    int q;
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        map<string,int> :: iterator it;
        int t,marks;
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> name >> marks; 
                it=m.find(name);
                if(it==m.end())
                {
                    m.insert(make_pair(name,marks));
                }
                else
                {
                    it->second=it->second+marks;   
                }
                break;
            case 2:
                cin >> name;
                m.erase(name);
                break;
            case 3:
                cin >> name;
                it=m.find(name);
                if(it==m.end())
                    cout << "0\n";
                else
                    cout << it->second << endl;
                break;
        } 
    }  
    return 0;
}
