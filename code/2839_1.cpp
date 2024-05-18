#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int tmp, n;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main()
{
    int input;
    int backA, backB;
    cin >> input >> backA >> backB;
    cout << endl
         << input << backA << backB << endl;
    int icm = backA * backB / gcd(backA, backB);
    cout << icm << endl;
    int countA = 0;
    int countB = 0;

    countA = input / icm * (icm / backA);
    input = input % icm;
    if (countA != 0)
    {
        countA -= (icm / backA);
        input += icm;
    }

    while (input > 0)
    {
        if (input % backA == 0)
        {
            countA += input / backA;
            input = 0;
        }
        else
        {
            countB += 1;
            input -= backB;
        }
    }
    cout << countA << " " << countB << endl;
    if (input == 0)
    {
        cout << countA + countB;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
