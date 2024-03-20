// A merchant has two types of idols, gold and silver.
// He has arranged the idols in the form of m*n grid,
// 	- the gold idols are represented as 1's
// 	- the silver idols are represented as 0's.

// Your task is to find the longest consecutive arrangement of gold idols,
// The arrangement can be either horizontal, vertical, diagonal or
// antidiagonal, but not the combination of these.

// Input Format:
// -------------
// Line-1: Two space separated integers m and n, grid size.
// Next m lines : n space separated integers, arrangement of idols.

// Output Format:
// --------------
// Print an integer, longest arranement of gold idols.

// Sample Input:
// ---------------
// 4 5
// 1 0 1 1 1
// 0 1 0 1 0
// 1 0 1 0 1
// 1 1 0 1 1

// Sample Output:
// ----------------
// 4

#include <bits/stdc++.h>
using namespace std;
int rows[4] = {0, 1, 1, 1};
int cols[4] = {1, 1, 0, -1};

bool outOfBounds(vector<vector<int>> &board, int r, int c)
{
    return min(r, c) < 0 || r >= board.size() || c >= board[0].size();
}

void dfs(vector<vector<int>> &board, vector<vector<bool>> &vis, int r, int c, int dir, int &ans, int cur)
{
    if (outOfBounds(board, r, c) || board[r][c] == 0)
    {
        ans = max(ans, cur);
        return;
    }
    vis[r][c] = true;
    dfs(board, vis, r + rows[dir], c + cols[dir], dir, ans, cur + 1);
    vis[r][c] = false;
}

int maxOccur(vector<vector<int>> &board, int m, int n)
{
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    int ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                if (board[i][j])
                    dfs(board, vis, i, j, d, ans, 0);
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));
    for (auto &r : board)
    {
        for (auto &c : r)
        {
            cin >> c;
        }
    }
    int ans = maxOccur(board, m, n);
    cout << ans;
}