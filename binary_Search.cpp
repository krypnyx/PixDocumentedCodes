#include <bits/stdc++.h>

using namespace std;
int func(int a[], int n, int value)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int mid = (i + j) >> 1;
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << func(a, n, x);
    // suppose the array contain the 1 2 3 4 5 6
    // func will return the index of passed value in log(n);
    // ex->func(a[],6,3) will return 2;
}