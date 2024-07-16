#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool pairComp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i; i < n; i++)
    {
        int first;
        int second;

        cin >> first;
        cin >> second;
        a.push_back(pair<int, int>(first, second));
    }
    sort(a.begin(), a.end(), less<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> endTimes;
    int result = 0;
    for (pair<int, int> p : a)
    {
        if (endTimes.empty())
        {
            endTimes.push(p.second);
        }
        else
        {
            if (endTimes.top() > p.first)
            {
                endTimes.push(p.second);
            }
            else
            {
                while (endTimes.top() <= p.first)
                    endTimes.pop();
                endTimes.push(p.second);
            }
        }
        if (result < endTimes.size())
            result = endTimes.size();
    }
    cout << result;
}