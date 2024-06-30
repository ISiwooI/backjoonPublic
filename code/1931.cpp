#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool Compare(const pair<int, int> &mt1, const pair<int, int> &mt2)
{
    if (mt1.second == mt2.second)
        return mt1.first < mt2.first;
    else
        return mt1.second < mt2.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    pair<int, int> mtvector[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int mts, mte;

        cin >> mts;
        cin >> mte;
        mtvector[i] = pair<int, int>(mts, mte);
    }
    sort(mtvector, mtvector + n, Compare);
    int end = 0;
    int count = 0;
    for (const pair<int, int> &element : mtvector)
    {
        if (end <= element.first)
        {
            end = element.second;
            count++;
        }
    }
    cout << count;
    return 0;
}
