#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    queue<int> queue;
    for (int i = 1; i <= n; i++)
    {
        queue.push(i);
    }
    bool b = true;
    while (queue.size() > 1)
    {
        if (b)
        {
            queue.pop();
        }
        else
        {
            queue.push(queue.front());
            queue.pop();
        }
        b = !b;
    }
    cout << queue.front();
}