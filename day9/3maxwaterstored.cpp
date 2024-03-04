// A Kid built a structure using building blocks,
// by placing the building-blocks adjacent to each other.

// A building-block is a vertical alignment of blocks.
// 	                                ___
// here one block each represents  as |___|.

// The following structure made up of using building blocks

//                           ___
//                       ___|___|    ___
//                      |___|___|_w_|___|___              ___
//                   ___|___|___|___|___|___| w   _w_  w |___|
//               ___|___|___|___|___|___|___|_w__|___|_w_|___|____________

//                0  1   3   4   2   3    2   0   1   0   2

// Once the structure is completed, kid pour water(w) on it.

// You are given a list of integers, heights of each building-block in a row.
//  Now your task How much amount of water can be stored by the structure.

//  Input Format:
//  -------------
//  Space separated integers, heights of the blocks in the structure.

// Output Format:
//  --------------
//  Print an integer,

// Sample Input:
// -------------
//  0 1 3 4 2 3 2 0 1 0 2
//  0 1 3 4 4 4 4 4 4 4 4
//  4 4 4 4 3 3 2 2 2 2 2

// Sample Output:
// --------------
// 6

// Explanation:
//  -----------
// In the above structure,  6 units of water (w represents the water in the structure)
// can be stored.

#include <bits/stdc++.h>
using namespace std;

int findWater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(nums.size()), right(nums.size());
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(nums[i], left[i - 1]);
        right[n - 1 - i] = max(nums[n - 1 - i], right[n - i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - nums[i];
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> nums;
    int n;
    while (ss)
    {
        ss >> n;
        nums.push_back(n);
    }
    // int x; cin>>x;
    nums.pop_back();
    // vector<int> nums(x);
    // for(int &i: nums) cin>>i;
    int ans = findWater(nums);
    cout << ans;
}