// Skandhanshi Infra Township constructed N Villas in a row.
// They planned to paint the villas with three colors,
// snow-white, sky-blue and light-green.
// And adjacent villas should not paint with same color.

// You are given the cost of painting each villa with these colors, cost[N][3].
// cost[i][0] is cost of painting with snow-white.
// cost[i][1] is cost of painting with sky-blue.
// cost[i][2] is cost of painting with light-green.
// where, 0 <= i < N.

// Your task is to find the minimum cost to paint all the villas.

// Input Format:
// -------------
// Line-1: An integer N, number of villas.
// Next N lines: 3 space separated integers, cost to paint the villas.

// Output Format:
// --------------
// Print an integer, minimum cost to paint all the villas.

// Sample Input:
// -------------
// 3
// 17 2 17
// 16 4 5
// 14 3 19

// Sample Output:
// --------------
// 10

// Explanation:
// ------------
// 1st Villa painted with sky-blue, 2nd Villa painted with light-green,
// 3rd Villa painted with sky-blue.
// Minimum cost: 2 + 5 + 3 = 10.

#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> &houses, int idx, int curColor)
{
    if (idx >= houses.size())
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        if (i == curColor)
            continue;
        ans = min(ans, recursion(houses, idx + 1, i));
    }
    return ans + houses[idx][curColor];
}

int memoization(vector<vector<int>> &houses, int idx, int curColor, vector<vector<int>> &memo)
{
    if (idx >= houses.size())
    {
        return 0;
    }
    if (memo[idx][curColor] != -1)
        return memo[idx][curColor];
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        if (i == curColor)
            continue;
        ans = min(ans, memoization(houses, idx + 1, i, memo));
    }
    return memo[idx][curColor] = ans + houses[idx][curColor];
}

int findMinCost(vector<vector<int>> &houses)
{
    int ans = INT_MAX;
    // for(int i=0;i<3;i++){
    //     ans = min(ans, recursion(houses, 0, i));
    // }
    vector<vector<int>> memo(houses.size() + 1, vector<int>(4, -1));
    for (int i = 0; i < 3; i++)
    {
        ans = min(ans, memoization(houses, 0, i, memo));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> houses;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        houses.push_back({a, b, c});
    }

    int ans = findMinCost(houses);
    cout << ans;
}