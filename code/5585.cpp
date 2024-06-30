#include <iostream>
using namespace std;

int main()
{
    int price;
    int change = 0;
    cin >> price;
    int changeMoney = 1000 - price;

    int n = 0;

    n += changeMoney / 500;
    changeMoney = changeMoney % 500;
    n += changeMoney / 100;
    changeMoney = changeMoney % 100;
    n += changeMoney / 50;
    changeMoney = changeMoney % 50;
    n += changeMoney / 10;
    changeMoney = changeMoney % 10;
    n += changeMoney / 5;
    changeMoney = changeMoney % 5;
    n += changeMoney;
    cout << n;
    return 0;
}