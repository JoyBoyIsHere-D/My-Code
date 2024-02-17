#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if (n==0||n==1)
        return 1;
    return n*fact(n-1);
}
int tailfact(int n, int k){
    if (n==0||n==1)
        return k;
    return tailfact(n-1,n*k);//faster because function call is the last statement

}

int main(){
    cout<<tailfact(20,1)<<endl;
    cout<<fact(20)<<endl;
    

    return 0;
}