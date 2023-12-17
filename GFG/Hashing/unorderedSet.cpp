#include <bits/stdc++.h>
using namespace std;

int countDistict(int arr[], int n){
    unordered_set<int> s(arr,arr+n);

    return s.size();
}

int main(){
    int arr[]={10,20,30,20,10,10};
    cout<<countDistict(arr,6);
    return 0;
}