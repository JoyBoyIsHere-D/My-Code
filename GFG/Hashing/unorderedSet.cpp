#include <bits/stdc++.h>
using namespace std;

void intersection(int a[], int n, int b[], int m){
    unordered_set<int> h(b,b+m);
    for ( int i=0;i<n;i++){
        if (h.find(a[i])!=h.end())
            cout<<a[i]<<" ";
    }

}

int countDistict(int arr[], int n){
    unordered_set<int> s(arr,arr+n);

    return s.size();
}

int main(){
    int arr[]={10,20,30,20,10,10};
    int a[]={1,2,3,4,5,6,8,7};
    int b[]={2,4,5,6,2,7,8};
    intersection(a,8,b,7);
    // cout<<countDistict(arr,6);
    return 0;
}