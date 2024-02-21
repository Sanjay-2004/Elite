// A game show hosted by the famous anchor Suma in which the celebrities compete
// with each other. The game show format is changed a bit, There are N celebrities
// participated now. And all of them answered correctly for a given question.
// Now everyone got a chance to play the money board game.
// Where i-th player standing at i-th index position of the top,
// and value of 'i' is 0 <= i < n.

// The money board is of size M*N, and N players has coins to drop from
// top of the money board. The money board is opened at top and bottom.

// Each cell in the board has a diagonal bar connecting two corners of the cell,
// that can redirect the coin to the rightside or to the leftside.

// - The bar that redirects the coin to the right,
// connected from the top-left corner to the bottom-right corner, indicated by 1.
// - The bar that redirects the coin to the left,
// connected from the top-right corner to the bottom-left corner, indicated by -1.

// The players drop their coins at the top of board. Each coin can get stuck
// in the board or fall out of the bottom. A coin gets stuck if it hits a "V"
// shaped pattern between two bars or if a bar redirects the coin into
// either wall of the board.

// Your task is to find and return an array result[] of size N,
// where result[i] is the index that the coin falls out of at the bottom
// after dropping the coin from the i-th index at the top,
// or -1 if the coin gets stuck in the board.

// Input Format:
// -------------
// Line-1: Two space separated integer M and N, size of the board.
// Next M lines: N space separated integers

// Output Format:
// --------------
// Print an array result.

// Sample Input-1:
// ---------------
// 5 5
// 1 1 1 -1 -1
// -1 -1 -1 1 -1
// 1 1 1 1 -1
// -1 -1 -1 -1 1
// -1 -1 -1 1 -1

// Sample Output-1:
// ----------------
// [-1, 0, -1, -1, -1]

// Sample Input-2:
// ---------------
// 5 5
// 1 1 1 1 1
// -1 -1 -1 -1 -1
// 1 1 1 1 1
// -1 -1 -1 -1 -1
// 1 1 1 1 1

// Sample Output-2:
// ----------------
// [1, 2, 3, 4, -1]

#include <bits/stdc++.h>
using namespace std;

bool outOfBounds(int maxcol, int b)
{
    return b < 0 || b >= maxcol;
}

int checkFinal(vector<vector<int>> &board, int m, int n, int r, int c)
{
    if (r >= m)
    {
        if (outOfBounds(n, c))
            return -1;
        return c;
    }
    if (outOfBounds(n, c) || (board[r][c] == 1 && (c + 1 < n && board[r][c + 1] == -1)) || (board[r][c] == -1 && (c - 1 > 0 && board[r][c - 1] == 1)))
    {
        return -1;
    }
    return checkFinal(board, m, n, r + 1, c + board[r][c]);
}

vector<int> findOut(vector<vector<int>> &board, int m, int n)
{
    vector<int> ans(n);
    for (int c = 0; c < n; c++)
    {
        for (int r = 0; r < m; r++)
        {
            ans[c] = checkFinal(board, m, n, 0, c);
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));
    for (auto &x : board)
    {
        for (int &a : x)
        {
            cin >> a;
        }
    }
    vector<int> ans = findOut(board, m, n);
    cout << "[";
    int i = 0;
    for (; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans[i] << "]";
}