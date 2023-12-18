#include <bits/stdc++.h>
using namespace std;

int longSubseq(int arr[], int n)
{
    unordered_set<int> h(arr, arr + n);
    int res = 1;
    for (auto x : h)
    {
        if (h.find(x - 1) == h.end())//to check whether it is the first element of the subsequence
        {
            int curr = 1;
            while (h.find(x + curr) != h.end())//to check the next n elements of the subsequence
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 3, 9, 2, 8, 2};
    cout << longSubseq(arr, 6);
    return 0;
}