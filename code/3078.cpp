#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    queue<int> nameVector;
    int lens[21] = {0};
    long long fcount = 0;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        int len = input.length();
        nameVector.push(len);
        lens[len]++;
        if (nameVector.size() > k + 1)
        {
            lens[nameVector.front()]--;
            nameVector.pop();
        }

        fcount += lens[len] - 1;
    }

    cout << fcount;
}