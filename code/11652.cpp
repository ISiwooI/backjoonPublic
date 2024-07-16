#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    map<long long, int> freq;

    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        freq[num]++;
    }

    int maxCount = 0;
    long long result = 0;

    for (pair<long long, int> pair : freq)
    {
        long long number = pair.first;
        int count = pair.second;

        if (count > maxCount)
        {
            maxCount = count;
            result = number;
        }
        else if (count == maxCount && number < result)
        {
            result = number;
        }
    }

    cout << result;

    return 0;
}