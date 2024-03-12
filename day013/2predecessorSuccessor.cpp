// Tejaswi playing a game. Game has a display of N numbers in a row, nums[].
// Tejaswi has to pick the numbers one after the other.

// Once Tejaswi picks a number num[i], she will score num[i] points and
// the number will be disappared on the board, simultaneously all the numbers
// having the value num[i]+1 or num[i]-1 also disappears.

// Tejaswi has to select the numbers, such that no more numbers will be left over
// on the board.

// Tejaswi wants to score maximum number of points.

// Initially Tejaswi has 0 points with her.
// Can you help Tejaswi to score maximum number of points.

// Input Format:
// -------------
// Line-1 -> an integers N, number of numbers on the game board.
// Line-2 -> N space separated integers, numbers on the game board nums[].

// Output Format:
// --------------
// Print an integer as result, maximum score she can get.

// Sample Input-1:
// ---------------
// 3
// 4 5 3

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------
// Pick a number 5 to score 5 points, simultaneously 4 is disappeared from display.
// Then, pick number 3 to score 3 points.
// Totally 8 is the score.

// Sample Input-2:
// ---------------
// 6
// 4 4 5 5 5 6

// Sample Output-2:
// ----------------
// 15

// Explanation:
// -------------
// Pick a number 5 to score 5 points, simultaneously all 4's and 6 are disappeared
// from display. Then, again pick the number 5 to score 5 points.
// And again pick the number 5 to score 5 points. Totally 15 is the score.

#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &nums, int idx)
{
    if (idx >= nums.size())
        return 0;

    int n = nums[idx];
    int c = 0;
    int i = idx;
    int next = idx;
    while (i < nums.size() && nums[i] == n || nums[i] == n + 1)
    {
        if (nums[i] == n)
        {
            c++;
            next++;
        }

        i++;
    }
    int incl = n * c + recursion(nums, i);
    int excl = recursion(nums, next);
    return max(incl, excl);
}

int memoisation(vector<int> &nums, int idx, vector<int> &memo)
{
    if (idx >= nums.size())
        return 0;

    if (memo[idx] != -1)
        return memo[idx];

    int n = nums[idx];
    int c = 0;
    int i = idx;
    int next = idx;
    while (i < nums.size() && nums[i] == n || nums[i] == n + 1)
    {
        if (nums[i] == n)
        {
            c++;
            next++;
        }

        i++;
    }
    int incl = n * c + memoisation(nums, i, memo);
    int excl = memoisation(nums, next, memo);
    return memo[idx] = max(incl, excl);
}

int findMaxValue(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    // return recursion(nums, 0);
    vector<int> memo(nums.size() + 1, -1);
    return memoisation(nums, 0, memo);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;

    int ans = findMaxValue(nums);
    cout << ans;
}