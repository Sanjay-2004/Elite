// There are N number of small cartoons and each cartoon will have a balloon of
// some color identified by a number. You are asked to select fixed number of
// P-cartoons as a subset every time and find the number of distinct number of
// colors of balloons in the number of cartoons "P" you pick everytime.

// The resultant cartoons ans will be N-P+1 and return it.

// The number of distinct number of balloons is:
//     nums[i:i+p-1] = [nums[i], nums[i+1], ..., nums[i+p-1]].

// Input Format:
// -------------
// Line-1: Two space separated integers, N and P
// Line-2: N space separated integers, nums[]

// Output Format:
// --------------
// Print the (N-P+1) integers as output.

// Sample Input-1:
// ---------------
// 7 4
// 1 2 2 3 3 4 4

// Sample Output-1:
// ----------------
// 3 2 3 2

// Explanation:
// ------------
// The number of distinct elements in each subarray of size P goes as follows:
// - nums[0:3] = [1,2,2,3] so ans[0] = 3
// - nums[1:4] = [2,2,3,3] so ans[1] = 2
// - nums[2:5] = [2,3,3,4] so ans[2] = 3
// - nums[3:6] = [3,3,4,4] so ans[3] = 2

// Sample Input-2:
// ---------------
// 6 3
// 1 1 1 1 1 1

// Sample Output-2:
// ----------------
// 1 1 1 1

// Explanation:
// ------------
// The number of distinct elements in each subarray goes as follows:
// - nums[0:2] = [1,1,1] so ans[0] = 1
// - nums[1:3] = [1,1,1] so ans[1] = 1
// - nums[2:4] = [1,1,1] so ans[2] = 1
// - nums[3:5] = [1,1,1] so ans[3] = 1

// Sample Input-3:
// ---------------
// 7 3
// 1 2 3 4 2 1 3

// Sample Output-3:
// ----------------
// 3 3 3 3 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    unordered_map<int, int> mp;

    vector<int> ans;
    int i = 0, j = 0;
    while (j < v)
    {
        mp[arr[j++]]++;
    }
    int sz = mp.size();
    ans.push_back(sz);
    while (j < arr.size())
    {
        mp[arr[i]]--;
        if (mp[arr[i]] == 0)
            mp.erase(arr[i]);
        i++;
        mp[arr[j++]]++;
        ans.push_back(mp.size());
    }
    for (int x : ans)
        cout << x << " ";
}