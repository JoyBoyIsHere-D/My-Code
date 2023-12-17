#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["gfg"] = 30;
    m["ide"] = 20;
    m.insert({"courses", 15});

    if(m.find("ide")!=m.end())
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}