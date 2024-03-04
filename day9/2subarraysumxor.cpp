// The integer array arr[] is given and print the resultant value of the bitwise OR
// of the sum of all the possible sub-arrays of the given array arr[].

// Note: A sub-array is a sequence of array-elements that could be drawn from other
//       sequence of array-elements by removing zero or more elements without changing
//       the order of the remaining elements.

// Input Format
// -------------
// Line-1: Read the size of array P.
// Line-2: Read the array elements(space separated values).

// Output Format
// --------------
// Print the resultant value.

// Sample input-1:
// ---------------
// 4
// 0 2 1 3
// Sample output-1:
// ----------------
// 7

// Explanation
// The sums of sub-arrays are
// 0 1 2 3 4 5 6.
// and bitwise OR operation
// 0 OR 1 OR 2 OR 3 OR 4 OR 5 OR 6 = 7.

// Sample input-2:
// ---------------
// 4
// 0 0 0 0
// Sample output-2:
// ----------------
// 0

// Explanation
// Only one sum sub-arrays i.e. 0.

#include <bits/stdc++.h>
using namespace std;

int tabulatedFindAns(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < arr.size(); j++)
        {
            sum += arr[j];
            ans |= sum;
        }
    }
    return ans;
}

void findAns(vector<int> &arr, int ind, int sum, int &ans)
{
    if (ind == arr.size())
    {
        ans |= sum;
        return;
    }
    findAns(arr, ind + 1, sum, ans);
    findAns(arr, ind + 1, sum + arr[ind], ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int ans = 0;
    // findAns(arr, 0, 0, ans);
    ans = tabulatedFindAns(arr);
    cout << ans;
}