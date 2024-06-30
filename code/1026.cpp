#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n, greater<int>());
    sort(b, b + n, less<int>());
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i] * b[i];
    }
    cout << result;
}