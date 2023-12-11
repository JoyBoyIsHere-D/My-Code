#include <bits/stdc++.h>
using namespace std;



int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long sum_a = 0, cnt_1 = 0;
    for (int x: a) {
        sum_a += x;
        if (x == 1) cnt_1++;
    }
    
    if (sum_a >= cnt_1 + n && n > 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    }
    return 0;
}