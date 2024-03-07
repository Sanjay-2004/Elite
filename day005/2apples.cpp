// There is a set of 'N' bags contains apples.
// Each bag carries few number of apples.
// You need to pick 'K' bags everytime from left to right.
// and find the bag which contains max number of apples 'M'.
// You need to return the value fo M each time.

// Bags array indicates the apples count in each bag.

// NOTE:
// -----
// Can you solve it in linear time?

// Input Format:
// -------------
// Line-1: Two space separated integers, N and K
// Line-2: N space separated integers,

// Output Format:
// --------------
// Print the (N-K+1) integer output.

// Sample Input-1:
// ---------------
// 8 3
// 1 2 3 5 4 6 8 7

// Sample Output-1:
// ----------------
// 3 5 5 6 8 8

// Explanation:
// ------------

// K Bags		Max
// -----------    -----
// 1 2 3			3
// 2 3 5			5
// 3 5 4			5
// 5 4 6			6
// 4 6 8			8
// 6 8 7			8

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> al;
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
        {
            al.erase(al.begin());
            al.push_back(arr[i]);
            cout << *max_element(al.begin(), al.end()) << " ";
        }
        else
        {
            al.push_back(arr[i]);
            if (i == k - 1)
            {
                cout << *max_element(al.begin(), al.end()) << " ";
            }
        }
    }
    return 0;
}