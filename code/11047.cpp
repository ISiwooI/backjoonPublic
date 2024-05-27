#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int N;
    int K;
    cin >> N;
    cin >> K;
    stack<int> s;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        s.push(input);
    }
    while (!s.empty())
    {
        result += K / s.top();
        K = K % s.top();
        s.pop();
    }
    cout << result;
}