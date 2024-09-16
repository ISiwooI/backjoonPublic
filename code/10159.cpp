#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    queue<int> Bq;
    queue<int> Sq;
    vector<pair<int, int>> v;
    map<int, bool> bmap;
    map<int, int> countmap;
    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;
        v.push_back(make_pair(f, s));
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bmap[j] = false;
        }
        int Bcount = 1;

        int num;
        Bq.push(i);

        while (!Bq.empty())
        {
            num = Bq.front();
            Bq.pop();
            for (auto p : v)
            {

                if (p.first == num && (bmap[p.second] == false))
                {
                    Bcount++;
                    Bq.push(p.second);
                    bmap[p.second] = true;
                }
            }
        }
        Sq.push(i);
        int Scount = 0;
        while (!Sq.empty())
        {
            num = Sq.front();
            Sq.pop();
            for (auto p : v)
            {

                if (p.second == num && (bmap[p.first] == false))
                {
                    Scount++;
                    Sq.push(p.first);
                    bmap[p.first] = true;
                }
            }
        }
        countmap[i] = Scount + Bcount;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << n - countmap[i] << "\n";
    }
}
