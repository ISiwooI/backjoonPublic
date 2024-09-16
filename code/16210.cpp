#include <iostream>

using namespace std;
class myStack
{
public:
    char stack[1000001];
    int top = -1;
    void push(char c)
    {
        stack[++top] = c;
    }
    char pop()
    {
        return stack[top--];
    }
    bool ppapChack()
    {
        if (top < 3)
        {
            return false;
        }
        else
        {
            if (stack[top - 3] == 'P' && stack[top - 2] == 'P' && stack[top - 1] == 'A' && stack[top] == 'P')
            {
                this->pop();
                this->pop();
                this->pop();
                this->pop();
                this->push('P');
                return true;
            }
            else
                return false;
        }
    }
    bool isEmpty()
    {
        return top < 0;
    }
};

int main()
{
    string input;
    cin >> input;
    bool isChacked = false;

    myStack myStack;
    for (char c : input)
    {
        myStack.push(c);
        while (myStack.ppapChack())
        {
        }
    }
    char re = myStack.pop();
    if (re == 'P' && myStack.isEmpty())
        cout << "PPAP";
    else
        cout << "NP";
    return 0;
}