#include <bits/stdc++.h>
using namespace std;

// void nonZeroes(vector <int> arr){
//     int count=0;
//     for (int i=0;i<arr.size();i++){
//         if (arr[i]!=0){
//             swap(arr[i],arr[count]);
//             count++;
//         }
//     }
//     for (int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
// }

void leftRotate(vector<int> arr)
{

    for (int i = 0; i < (arr.size() - 1); i++)
    {
        swap(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void reverse(vector<int> arr, int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void leftRotateD(vector<int> arr, int d)
{
    int n = arr.size();
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int max1(int arr[], int n)
{
    int res = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            res++;
            curr = max(res, curr);
        }
        else
            res = 0;
    }
    return curr;
}
int missingNumber(vector<int>& array, int n) {
        
        // Your code goes here
        sort(array.begin(),array.end());
        
        for (int i=0;i<n;i++){
            if (array[i]!=(i+1)){
                cout<<(i+1);
                break;
            }
        }
    }

int main()
{
    int arr[] = {2,4,6,7,1,3};


    return 0;
}