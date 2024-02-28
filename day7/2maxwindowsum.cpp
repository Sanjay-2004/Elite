// There is an integer array of N heights. You have to pick certain number of heights
// from the array everytime. Find the maximum  sum of all the heights picked
// everytime that meet the following conditions:
//     - The length of the subarray is L, and
//     - All the heights of the subarray picked are distinct.

// Return the maximum subarray sum of all the height subarrays that meet the
// conditions. If no heights subarray meets the conditions, return 0.

// - A subarray is a contiguous non-empty sequence of elements within an array.

// Input Format:
// -------------
// Line-1: Two space separated integers, N and L
// Line-2: N space separated integers, height[].

// Output Format:
// --------------
// Print an integer result.

// Sample Input-1:
// ---------------
// 7 3
// 7 7 7 1 5 4 2

// Sample Output-1:
// ----------------
// 13

// Explanation:
// ------------
// The subarrays of length 3 of height array are:
//     - [7,7,7] this subarray does not meet the requirement because the 7 is repeated.
//     - [7,7,1] this subarray does not meet the requirement because the 7 is repeated.
//     - [7,1,5] this subarray meets the requirements and its sum is 13.
//     - [1,5,4] this subarray meets the requirements and its sum is 10.
//     - [5,4,2] this subarray meets the requirements and its sum is 11.

// Return 13 because it is the maximum subarray sum of all the subarrays
// that meet the conditions

// Sample Input-2:
// ---------------
// 3 3
// 7 7 7

// Sample Output-2:
// ----------------
// 0

// Explanation:
// ------------
// The subarrays of length 3 of height array are:
// - [7,7,7] which does not meet the requirements because the element 7 is repeated.

// Return 0 because no subarrays meet the conditions.

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &arr, int w)
{
    unordered_map<int, int> mp;
    int ans = 0;
    int i = 0, j = 0;
    int sum = 0;
    while (j < w)
    {
        sum += arr[j];
        // cout<<sum<<endl;
        mp[arr[j++]]++;
    }
    if (mp.size() == w)
        ans = sum;
    while (j < arr.size())
    {
        mp[arr[i]]--;
        sum -= arr[i];
        if (mp[arr[i]] == 0)
            mp.erase(arr[i]);
        i++;
        sum += arr[j];
        mp[arr[j++]]++;
        // cout<<sum<<endl;
        if (mp.size() == w)
            ans = max(ans, sum);
        // cout<<"ans:"<<ans<<endl;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    int ans = findMax(arr, m);

    cout << ans;
}