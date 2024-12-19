#include <iostream>
#include <vector>
using namespace std;
int n;
int T[16] = {
    0,
};
int P[16] = {
    0,
};
int mP[16]{
    0,
};
int result = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
        cin >> P[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + T[i] > n)
            P[i] = 0;
        if (i == n - 1)
            mP[i] = P[i];
        else
        {
            int m = P[i];
            if (T[i] + i < n)
                m += mP[T[i] + i];
            mP[i] = m > mP[i + 1] ? m : mP[i + 1];
        }
        if (result < mP[i])
            result = mP[i];
    }
    cout << result;
}