#include <bits/stdc++.h>
using namespace std;

int maxEvOddSub(int arr[],int n){
    int curr=1;
    int res=1;
    for (int i=0;i<n;i++){
        if ((arr[i]%2==0 && arr[i-1]%2==1)||(arr[i-1]%2==0 && arr[i]%2==1)){
        curr++;
        res=max(curr,res);
        }
        else
        curr=1;
    }
    return res;
}

int main(){
    int arr[]={5,10,20,6,3,8};
    cout<<maxEvOddSub(arr,6);
    return 0;
}