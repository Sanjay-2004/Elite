// There are N computers in a network, all the computers are connected as tree
// structure. And one new connection is added in the Network. The computers in
// the network are identified with their IDs, the IDs are numbered between 1 to N.

// The connections in the network is given as coonection[i] = [comp-A, comp-B],
// there is a connection between comp-A and comp-B.

// Your task is to remove a connection in the network and print it, so that
// all the computers are connected as tree structure. If there are multiple
// options to remove, remove the connection that occurs last in the input.

// Input Format:
// -------------
// Line-1: Two space separated integers N, number of computers.
// Next N lines: Two space separated integers, comp-A & comp-B.

// Output Format:
// --------------
// Print the connection which is removed.

// Sample Input-1:
// ---------------
// 6
// 1 2
// 3 4
// 3 6
// 4 5
// 5 6
// 2 3

// Sample Output-1:
// ---------------
// 5 6

// Sample Input-2:
// ---------------
// 4
// 1 2
// 2 3
// 3 4
// 2 4

// Sample Output-2:
// ---------------
// 2 4

#include <bits/stdc++.h>
using namespace std;

int findParent(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = findParent(parent[x], parent);
}
void unionSet(int v1, int v2, vector<int> &parent, vector<int> &rank)
{
    int p1 = findParent(v1, parent);
    int p2 = findParent(v2, parent);
    if (p1 == p2)
        return;
    if (rank[p1] < rank[p2])
        parent[p1] = p2;
    else if (rank[p2] < rank[p1])
        parent[p2] = p1;
    else
    {
        parent[p1] = p2;
        rank[p2]++;
    }
}

pair<int, int> findExtra(vector<pair<int, int>> &edges)
{
    int n = edges.size();
    vector<int> parent(n + 1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(n + 1, 0);
    auto ans = edges[0];
    for (int i = 0; i < n; i++)
    {
        if (findParent(edges[i].first, parent) == findParent(edges[i].second, parent))
        {
            ans = edges[i];
        }
        else
        {
            unionSet(edges[i].first, edges[i].second, parent, rank);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    auto ans = findExtra(edges);
    cout << ans.first << " " << ans.second;
}