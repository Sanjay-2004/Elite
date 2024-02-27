// Budget Padmanabham planned to visit the tourist places. There are N tourist
// places in the city. The tourist places are numbered from 1 to N.

// You are given the routes[] to travel between the tourist places in the city.
// where routes[i]=[place-1, place-2, price], A route is a bi-directional route.
// You can travel from place-1 to place-2 or place-2 to place-1 with the given price.

// Your task is to help Budget Padmanabham to find the cheapest route plan, to
// visit all the tourist places in the city. If you are not able to find such plan,
// print -1.

// Input Format:
// -------------
// Line-1: Two space separated integers N and R,number of places and routes.
// Next R lines: Three space separated integers, start, end and price.

// Output Format:
// --------------
// Print an integer, minimum cost to visit all the tourist places.

// Sample Input-1:
// ---------------
// 4 5
// 1 2 3
// 1 3 5
// 2 3 4
// 3 4 1
// 2 4 5

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------
// The cheapest route plan is as follows:
// 1-2, 2-3, 3-4 and cost is 3 + 4 + 1 = 8

// Sample Input-2:
// ---------------
// 4 3
// 1 2 3
// 1 3 5
// 2 3 4

// Sample Output-2:
// ----------------
// -1

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>> adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(V, 0);

    pq.push({0, 0});
    int ans = 0;
    int cnt = 0;

    while (pq.size())
    {
        auto x = pq.top();
        pq.pop();
        if (vis[x.second])
            continue;
        ans += x.first;
        cnt++;
        vis[x.second] = 1;
        for (auto it : adj[x.second])
        {
            if (!vis[it.first])
                pq.push({it.second, it.first});
        }
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});
    }
    int ans = spanningTree(v, adj);
    for (auto x : adj)
    {
        if (x.size() == 0)
            ans = -1;
    }
    cout << ans;
}