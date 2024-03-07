// In an International school 9th standard students have been assigned a task.

// Given a list of numbers nums[] and three values p, q and r.
// They have to solve the equation function(x)=p(x^2)+q(x)+r,
// for each number(x) in the given list nums[],
// and print the resultant values in the sorted order.

// Input Format:
// -------------
// Line-1: An integer N, size of list nums[].
// Next N lines: space separated integers, nums[]
// Last Line: 3 space separated integers, P, Q and R.

// Output Format:
// --------------
// Print a list of numbers[].

// Sample Input-1:
// ---------------
// 4
// -3 -2 2 4
// 2 3 5

// Sample Output-1:
// ----------------
// 7 14 19 49

// Sample Input-2:
// ---------------
// 4
// -3 -2 1 2
// -2 3 5

// Sample Output-2:
// ----------------
// -22 -9 3 6

#include <bits/stdc++.h>
using namespace std;

int check(int x, int p, int q, int r)
{
    return p * (x * x) + q * x + r;
}

void countingSort(vector<int> &arr)
{
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < count.size(); i++)
    {

        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    arr = output;
}

void solve(vector<int> &vec, int n, int p, int q, int r)
{
    vector<int> ans;
    vector<int> neg;
    vector<int> pos;

    for (auto i : vec)
    {
        if (i < 0)
            neg.push_back(check(i, p, q, r));
        else
            pos.push_back(check(i, p, q, r));
    }

    if (p < 0)
    {
        for (int i = 0; i < neg.size(); i++)
            ans.push_back(neg[i]);

        for (int i = pos.size() - 1; i >= 0; i--)
            ans.push_back(pos[i]);
    }
    else if (p > 0)
    {
        for (int i = neg.size() - 1; i >= 0; i--)
            ans.push_back(neg[i]);

        for (int i = 0; i < pos.size(); i++)
            ans.push_back(pos[i]);
    }

    countingSort(ans);

    for (auto i : ans)
        cout << i << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int p, q, r;
    cin >> p >> q >> r;

    solve(vec, n, p, q, r);
    return 0;
}