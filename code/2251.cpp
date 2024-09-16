#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<int> result;
int A, B, C;
int a, b, c;
// 지역변수로 선언하면 스택에 생성되어 스택의 크기 제한에 따라 런타임에러가 생기지반 전역변수로 선언하면 힙 영역에 생성되어 그 제한으로부터 자유롭습니다.
bool visited[201][300][300] = {
    false,
};
int main()
{

    queue<pair<pair<int, int>, int>> queue;
    cin >> A;
    cin >> B;
    cin >> C;
    queue.push(make_pair(make_pair(0, 0), C));
    while (!queue.empty())
    {

        a = queue.front().first.first;
        b = queue.front().first.second;
        c = queue.front().second;
        queue.pop();
        if (visited[a][b][c] == true)
            continue;
        visited[a][b][c] = true;

        if (a == 0)
            result.push_back(c);

        if (a + b > B)
            queue.push(make_pair(make_pair(a + b - B, B), c));
        else
            queue.push(make_pair(make_pair(0, a + b), c));
        if (a + c > C)
            queue.push(make_pair(make_pair(a + c - C, b), C));
        else
            queue.push(make_pair(make_pair(0, b), a + c));
        if (b + a > A)
            queue.push(make_pair(make_pair(A, b + a - A), c));
        else
            queue.push(make_pair(make_pair(b + a, 0), c));
        if (b + c > C)
            queue.push(make_pair(make_pair(a, b + c - C), C));
        else
            queue.push(make_pair(make_pair(a, 0), b + c));
        if (c + a > A)
            queue.push(make_pair(make_pair(A, b), c + a - A));
        else
            queue.push(make_pair(make_pair(c + a, b), 0));
        if (c + b > B)
            queue.push(make_pair(make_pair(a, B), c + b - B));
        else
            queue.push(make_pair(make_pair(a, b + c), 0));
    }
    sort(result.begin(), result.end());
    unique(result.begin(), result.end());
    for (int i : result)
    {
        cout << i << " ";
    }
}