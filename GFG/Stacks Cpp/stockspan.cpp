#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {60, 10, 15, 20, 35, 40};
    stack<int> st;
    int n = sizeof(arr) / sizeof(arr[0]);
    st.push(0);
    int span = 1;
    cout << span << " ";
    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        span = st.empty() ? i + 1 : i - st.top();
        cout << span << " ";
        st.push(i);
    }
    return 0;
}