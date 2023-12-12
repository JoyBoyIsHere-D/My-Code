#include <bits/stdc++.h>
using namespace std;

void naiveSearch(string txt, string pat){
    int n=txt.length();
    int m=pat.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for (j=0;j<m;j++)
            if (pat[j]!=txt[j+i])
            break;

        if(j==m)
        cout<<i<<" ";

    }
    
}

int main(){
    string txt,pat;
    cin>>txt>>pat;
    naiveSearch(txt,pat);
    return 0;
}