// Mr Suleman is given a checkerboard of size 400*400, where the indices starts
// from (-200,-200) and ends at (199,199). In one step, he can move the box from
// position (p,q) to one of the following positions in L shape like as follows:
// 	- (p-2, q-1), (p-2, q+1), (p+2, q-1), (p+2, q+1)
// 	- (p-1, q+2), (p+1, q+2), (p-1, q-2), (p+1, q-2)

// Initially the box is at (0,0) position, and need to move the box to position (m,n).
// You will be given two integers m and n indicates the position(m,n).

// Now your task is to help by Mr Suleman to find the minimum number of steps
// required to move the box from (0,0) to (m,n).

// Note: It is allowed to move out of the board also.

// Input Format:
// -----------------
// Two space separated integers, m and n, position.

// Output Format:
// ------------------
// Print an integer, minimum number of steps to reach (m,n).

// Sample Input-1:
// ---------------
// 2 4

// Sample Output-1:
// ----------------
// 2

// Explanation:
// -------------
// Initially, you are at (0,0) position, you can reach (2,4) as follows:
// (0,0) -> (1, 2) -> (2, 4)

// Sample Input-2:
// ---------------
// 4 7

// Sample Output-2:
// ----------------
// 5

// Explanation:
// ------------
// Initially, you are at (0,0) position, you can reach (4,7) as follows:
// (0,0) -> (1, 2) -> (2, 4) -> (1, 6) -> (3, 5) -> (4, 7)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(500, vector<bool>(500, 0));
    q.push({0, 0});
    vis[250][250] = 1;
outer:
    while (q.size())
    {
        int sz = q.size();
        while (sz--)
        {
            auto x = q.front();
            q.pop();
            if (x.first == a && x.second == b)
            {
                cout << ans;
                return 0;
            }
            for (auto z : dirs)
            {
                int nx = x.first + z[0];
                int ny = x.second + z[1];
                if (!vis[250 + nx][250 + ny])
                {
                    q.push({nx, ny});
                    vis[250 + nx][250 + ny] = 1;
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
