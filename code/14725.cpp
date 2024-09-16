#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Node
{
public:
    vector<Node> links;
    string value;
    int floor;
    Node(string str)
    {
        links = vector<Node>();
        floor = -1;
        value = str;
    }
    Node(string str, int floor)
    {
        links = vector<Node>();
        value = str;
        this->floor = floor;
    }

    void PrintNode()
    {
        sort(links.begin(), links.end(), less<Node>());
        if (floor >= 0)
        {
            for (int i = 0; i < floor; i++)
            {
                cout << "--";
            }
            cout << value << endl;
        }
        if (links.empty())
            return;
        for (Node &link : links)
        {
            link.PrintNode();
        }
    }
    bool operator<(const Node &node) const
    {
        return this->value < node.value;
    }
    bool operator<=(const Node &node) const
    {
        return this->value <= node.value;
    }
    void AddNode(queue<string> &sarry)
    {
        if (sarry.empty())
            return;
        string temp = sarry.front();
        sarry.pop();
        for (Node &link : links)
        {
            if (link.value == temp)
            {
                link.AddNode(sarry);
                return;
            }
        }
        links.push_back(Node(temp, this->floor + 1));
        links.back().AddNode(sarry);
        return;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<queue<string>> qarry;
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        qarry.push_back(queue<string>());
        for (int j = 0; j < k; j++)
        {
            string temp;
            cin >> temp;
            qarry[i].push(temp);
        }
    }
    Node node = Node("");
    for (queue<string> &q : qarry)
    {
        node.AddNode(q);
    }
    node.PrintNode();
}