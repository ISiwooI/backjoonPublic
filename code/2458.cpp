#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <list>
using namespace std;
char grap[501][501] = {
    0,
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    cin >> m;
    int result;
    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        grap[f][s] = 1;
        grap[s][f] = -1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (grap[i][k] < 0 && grap[k][j] < 0)
                    grap[i][j] = -1;
                else if (grap[i][k] > 0 && grap[k][j] > 0)
                    grap[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (grap[i][j] == 0 && grap[j][i] == 0)
                continue;
            count++;
        }
        if (count + 1 == n)
            result++;
    }
    cout << result;
}
