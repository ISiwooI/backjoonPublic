#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string input;
    cin >> input;

    int ml = 0;
    int cl = 1;
    stack<pair<char, int>> s;
    vector<int> v;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            s.push(pair<char, int>(input[i], i));
        }
        else if (input[i] == ')')
        {
            if (s.empty())
            {
                continue;
            }
            else if (s.top().first == '(')
            {
                v.push_back(s.top().second);
                v.push_back(i);
                s.pop();
            }
        }
    }
    sort(v.begin(), v.end());
    int cu = -2;
    for (int i : v)
    {
        if (cu + 1 == i)
        {
            cl++;
            cu = i;
            ml = max(cl, ml);
        }
        else
        {
            cu = i;
            cl = 1;
        }
    }

    cout << ml;
}
