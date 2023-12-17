#include <bits/stdc++.h>
using namespace std;

bool isSum(int arr[],int n,int sum){
    int pre=0;
    unordered_set<int> h;
    for (int i=0;i<n;i++){
        pre+=arr[i];
        if (h.find(pre-sum)!=h.end())
            return true;
        if (pre==sum)
            return true;
        h.insert(pre);
    }
    return false;
}


bool is0Sum(int arr[],int n){
    int pre=0;
    unordered_set<int> h;
    for (int i=0;i<n;i++){
        pre+=arr[i];
        if (h.find(pre)!=h.end())
            return true;
        if (pre==0)
            return true;
        h.insert(pre);
    }
    return false;
}
int main(){
    int arr[]={-3,4,-3,-1,1};
    cout<<is0Sum(arr,5)<<endl;
    cout<<isSum(arr,5,-4);
    return 0;
}