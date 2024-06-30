#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
/*void split(string in, vector<string> &out, string separator)
{
    out.clear();
    int prev = 0;
    int cur;
    cur = in.find(separator);
    while (cur != string::npos)
    {
        out.push_back(in.substr(prev, cur - prev));
        prev = cur + separator.length();
        cur = in.find(separator, prev);
    }
    out.push_back(in.substr(prev));
}*/
void split(string in, vector<string> &out, char separator)
{
    out.clear();
    stringstream strstream(in);
    string temp;
    while (getline(strstream, temp, separator))
    {
        out.push_back(temp);
    }
}
int merge(string item)
{
    vector<string> tmp;
    int result = 0;
    split(item, tmp, '+');
    for (string pitem : tmp)
    {
        result += stoi(pitem);
    }
    return result;
}
int main()
{
    string input;
    string temp;
    cin >> input;

    vector<string> mstrings;
    vector<int> minusValues;
    split(input, mstrings, '-');
    for (string item : mstrings)
    {
        minusValues.push_back(merge(item));
    }
    int result = minusValues[0] * 2;
    for (int item : minusValues)
    {
        result -= item;
    }
    cout << result;
}