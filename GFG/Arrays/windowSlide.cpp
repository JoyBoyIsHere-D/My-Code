#include <bits/stdc++.h>
using namespace std;


int maxSumK(int arr[], int n, int k){
    int res=INT_MIN;
    for (int i=0;i<n-k+1;i++){
        int curr=0;
        for (int j=i;j<i+k;j++){
            curr+=arr[j];
            res=max(curr,res);
        }
    }
    return res;
}

int maxSumK2(int arr[],int n, int k){
    int curr=0;
    for (int i=0;i<k;i++){
        curr+=arr[i];
    }

    int res=INT_MIN;
    for (int i = k; i < n; i++)//uses the approach of Window Sliding
    { //Here i is the index of the new element in a window
        curr+= arr[i]-arr[i-k];
        res=max(res,curr);
    }
    return res;
}


int main(){
    int arr[]={10,5,-2,20,1};
    cout<<maxSumK2(arr,5,3);
    return 0;
}