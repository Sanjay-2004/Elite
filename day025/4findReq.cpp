// You are given a set of N integers, and a value to find F. Initially a variable,
// 'total' is set to 0. You can perform either addition(+) or subtraction(-)
// of every integer from the set to the 'total'. The resultant total should be
// equal to the value F.

// Your task is to find out the number of ways, you can make the 'total' equal to
// the value F.

// Input Format:
// -------------
// Line-1: Two integers N and F.
// Line-2: N space separated integers

// Output Format:
// --------------
// Print an integer, number of ways.

// Sample Input:
// -------------
// 5 3
// 1 1 1 1 1

// Sample Output:
// --------------
// 5

// Explanation:
// ------------
// total = -1+1+1+1+1 = 3 -> total=value-F
// total = +1-1+1+1+1 = 3 -> total=value-F
// total = +1+1-1+1+1 = 3 -> total=value-F
// total = +1+1+1-1+1 = 3 -> total=value-F
// total = +1+1+1+1-1 = 3 -> total=value-F

// NOTE: + means addition, - means subtraction

#include <bits/stdc++.h>
using namespace std;

void backTrack(int idx, vector<int> &nums, int &ans, int cur, int f)
{
    if (idx == nums.size())
    {
        if (cur == f)
            ans++;
        return;
    }

    backTrack(idx + 1, nums, ans, cur + nums[idx], f);
    backTrack(idx + 1, nums, ans, cur - nums[idx], f);
}

signed main()
{
    int n, f;
    cin >> n >> f;
    vector<int> nums(n);

    for (int &i : nums)
        cin >> i;

    int ans = 0;
    backTrack(0, nums, ans, 0, f);

    cout << ans;
}