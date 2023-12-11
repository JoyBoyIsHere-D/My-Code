#include <bits/stdc++.h>
using namespace std;

bool isSort(int arr[], int n)
{
    bool res = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] <= arr[i])
            res = true;
        else
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (isSort(arr, n) || n==1)
            cout << "YES" << endl;
        else if (k > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}