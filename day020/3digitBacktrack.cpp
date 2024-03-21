// Basanthi interested playing with digits.
// He wants create a set of integers of length N, using the digits[0-9].
// The rules to create the integers are as follows:
// 	- digits in each integer are like d0,d1,d2...dn-1
// 	- and |d0-d1| = |d1-d2| = |d2-d3| ... |dn-2 - dn-1|= D

// Basanthi is given two integers N and D, where N is length of the integer and
// D is the difference. Can you help Basanthi, to create such list of integers
// and print all the possible integers in ascending order

// Note:
// -----
// Integers with leading 0's are not allowed

// Input Format:
// -------------
// Two space separated integers N and K.

// Output Format:
// --------------
// Print all the possible integers in ascending order.

// Sample Input-1:
// ---------------
// 3 6

// Sample Output-1:
// ----------------
// [171, 282, 393, 606, 717, 828, 939]

// Sample Input-2:
// ---------------
// 2 3

// Sample Output-2:
// ----------------
// [14, 25, 30, 36, 41, 47, 52, 58, 63, 69, 74, 85, 96]

#include <bits/stdc++.h>
using namespace std;

void backTrack(unordered_set<string> &ans, int dig, int diff, string cur, int st)
{
    if (cur.size() == dig)
    {
        // cout<<cur<<endl;
        if (cur[0] != '0')
            ans.insert(cur);
        return;
    }

    if (st + diff < 10)
        backTrack(ans, dig, diff, cur + to_string(st + diff), st + diff);
    if (st - diff >= 0)
        backTrack(ans, dig, diff, cur + to_string(st - diff), st - diff);
}

vector<string> findNums(int n, int d)
{
    unordered_set<string> st;
    for (int i = 0; i < 10; i++)
    {
        backTrack(st, n, d, "", i);
    }
    vector<string> ans(st.begin(), st.end());
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<string> ans = findNums(n, d);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
            cout << "[";
        cout << ans[i];
        if (i == ans.size() - 1)
            cout << "]";
        else
            cout << ", ";
    }
    return 0;
}