#include <bits/stdc++.h>
using namespace std;

bool subsequence(string &s1, string &s2, int n, int m){
    if (m==0)
        return true;
    if (n==0)
        return false;

    if (s1[n-1]==s2[m-1])
        return subsequence(s1,s2,n-1,m-1);
    else
        return subsequence(s1,s2,n-1,m);
}


int main(){
    string s1="geeksofgeeks";
    string s2="gfl";

    cout<<subsequence(s1,s2,s1.length(),s2.length());
    return 0;
}