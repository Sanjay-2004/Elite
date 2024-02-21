// Ibrahim is an interior designer wants to color wall of size M *N.
// He plans to color the wall and put lights of two different colors
// The designer can lit the wall using M *N lights.The lights are Blue or pink in color.
// Blue colored lights represented with digit -1 and pink colored lights represented with digit -0.
// The Blue colored lights forms different shapes,that are connected 4 directonally.
// The directons are upwards, downwards, left, and right.
// Ibrahim got an idea to count the unique shapes formed by blue colored lights.

// You will be given the decorated wall as a matrix wall[][].
// Your task is to help Ibrahim to count the unique shapes by the lights.

// Input Format : -- -- -- -- -- -- -Line -1 :
// Two space separated integers M and N, size of the wall.Next M lines : N space separated integers, either 0 or 1.

// Output Format : -- -- -- -- -- -- --Print an integer, Number of distinct shapes formed by Blue Lights.
// Sample Input -1 :
// 4 5
// 1 1 0 1 1
// 1 1 0 0 1
// 0 0 0 0 0
// 1 1 0 0 0

// Sample Output -1 :
// 3

// Sample Input -2 :
// 5 5
// 1 1 0 1 1
// 1 0 0 0 1
// 0 0 0 0 0
// 1 0 0 0 1
// 1 1 0 1 1

// Sample Output -2 :
// 4

#include <bits/stdc++.h>
using namespace std;

int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char dir[4] = {'U', 'R', 'D', 'L'};

bool outOfBounds(vector<vector<int>> &wall, int r, int c)
{
    return min(r, c) < 0 || r >= wall.size() || c >= wall[0].size();
}

void dfs(vector<vector<int>> &wall, string &s, int r, int c, int d, int cnt)
{
    if (outOfBounds(wall, r, c) || wall[r][c] == 0)
        return;
    if (d != -1)
        s += dir[d] + to_string(cnt);
    wall[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        dfs(wall, s, nr, nc, i, cnt + 1);
    }
}

int findHouses(vector<vector<int>> &wall, int r, int c)
{
    unordered_set<string> res;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (wall[i][j])
            {
                string s = "";
                dfs(wall, s, i, j, -1, 1);
                // cout<<s<<endl;
                res.insert(s);
            }
        }
    }
    return res.size();
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> wall(r, vector<int>(c));
    for (auto &row : wall)
    {
        for (auto &col : row)
        {
            cin >> col;
        }
    }
    int ans = findHouses(wall, r, c);
    cout << ans;
}
