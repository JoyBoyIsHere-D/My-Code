#include <bits/stdc++.h>
using namespace std;
const int CHAR=256;

int leftMostNonRepeat(string str){
    int fi[CHAR];
    fill(fi,fi+CHAR,-1);//STL function to fill all the values with -1
    for (int i=0;i<str.length();i++){
        if (fi[str[i]]==-1)
            fi[str[i]]=i;
        else
            fi[str[i]]=-2;//-2 means that it has repeated
    }

    int res=INT_MAX;
    for (int i=0;i<CHAR;i++){
        if(fi[i]>=0)
            res=min(res,fi[i]);
    }
    return (res==INT_MAX)?-1:res;
}

int leftMostRepeat(string str){
    int count[CHAR]={0};
    for (int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for (int i=0;i<str.length();i++){
    
        if(count[str[i]]>1)
            return i;
    }
    return -1;

}

int main(){
    string str="abbcbda";
    cout<<leftMostNonRepeat(str);
    return 0;
}