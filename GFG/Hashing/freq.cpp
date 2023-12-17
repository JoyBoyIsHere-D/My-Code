#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
    {
        h[arr[i]]++;
    }
    for (auto x : h)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    int arr[] = {10, 30, 50, 10, 20, 30, 50, 50, 30};
    countFreq(arr, 9);
    return 0;
}