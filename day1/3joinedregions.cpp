// There are N cities, and M routes[], each route is a path between two cities.
// routes[i] = [city1, city2], there is a travel route between city1 and city2.
// Each city is numbered from 0 to N-1.

// There are one or more Regions formed among N cities.
// A Region is formed in such way that you can travel between any two cities
// in the region that are connected directly and indirectly.

// Your task is to findout the number of regions formed between N cities.

// Input Format:
// -------------
// Line-1: Two space separated integers N and M, number of cities and routes
// Next M lines: Two space separated integers city1, city2.

// Output Format:
// --------------
// Print an integer, number of regions formed.

// Sample Input-1:
// ---------------
// 5 4
// 0 1
// 0 2
// 1 2
// 3 4

// Sample Output-1:
// ----------------
// 2

// Sample Input-2:
// ---------------
// 5 6
// 0 1
// 0 2
// 2 3
// 1 2
// 1 4
// 2 4

// Sample Output-2:
// ----------------
// 1

// Note: Look HINT for explanation.

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
int findRegions(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j])
                unionSet(i, j, parent, rank);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (findParent(i, parent) == i)
            ans++;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        adj[i][i] = 1;
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    cout << findRegions(adj);
}