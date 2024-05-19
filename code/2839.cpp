#include <iostream>

using namespace std;
int main()
{
    int input;
    cin >> input;
    int fivB = 0;
    int thB = 0;
    cout << input << endl;
    fivB = input / 15 * 3;
    input = input % 15;
    if (fivB != 0)
    {
        fivB -= 3;
        input += 15;
    }

    while (input > 0)
    {
        if (input % 5 == 0)
        {
            fivB += input / 5;
            input = 0;
        }
        else
        {
            thB += 1;
            input -= 3;
        }
    }
    if (input == 0)
    {
        cout << fivB + thB;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
