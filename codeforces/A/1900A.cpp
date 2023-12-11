#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin>>str;

        int res=0,maxr=0,curr=0;
        for (int i = 0; i < n; i++)
        {
            if (str[i]=='.'){
                res++;
                curr++;
                maxr=max(maxr,res);
                }
            else
                res=0;

        }

        if (maxr>2)
            cout<<2<<endl;
        else  
            cout<<curr<<endl;
        
    }
    return 0;
}