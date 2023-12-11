#include<iostream>
using namespace std;

bool sort(int arr[],int n){

    if (n==1){
        return true;
    }

    bool rest=sort(arr+1,n-1); //arr+1 means the array index from 0+1
    return (rest && arr[0]<arr[1]);
}

int main(){


    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){

        cin>>arr[i];
    }

    cout<<sort(arr,n);
    return 0;
}