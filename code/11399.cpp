#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<int> P = vector<int>(n, 0);
    //    int[] P = int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    int result = 0;
    int sum = 0;
    /*for (int i2 = 0; i2 < n; i2++)
    {
        sum += P[i2];
        result += sum;
    }*/
    for (int i = 1; i <= n; i++)
    {
        result += accumulate(P.begin(), P.begin() + i, 0);
    }
    cout << result;
    return 0;
}