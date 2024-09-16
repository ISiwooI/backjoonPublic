#include <iostream>
#include <regex>

using namespace std;
int main()
{
    string input;
    cin >> input;
    regex reg("[CAMBRIDGE]");
    string result = regex_replace(input, reg, "");
    cout << result;
}