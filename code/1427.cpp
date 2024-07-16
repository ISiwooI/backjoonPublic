#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ary;
    while (n != 0)
    {
        ary.push_back(n % 10);
        n /= 10;
    }
    sort(ary.begin(), ary.end(), greater<int>());
    for (int i : ary)
    {
        cout << i;
    }
    return 0;
}