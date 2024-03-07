// Given an array of integer elements, ele[], YOur task is to find and print
// the number of the subarrays, which gives you an even value after multiplication
// of the elements in it.

// Input Format:
// -------------
// Line-1: An integer N, number of elements.
// Line-2: Space separated elements.

// Output Format:
// --------------
// Print number of possible subarrays.

// Sample Input-1:
// ---------------
// 4
// 5 8 9 17

// Sample Output-1:
// ----------------
// 6

// Explanation:
// ------------
// 5 x 8 = 40
// 5 x 8 x 9 = 360
// 5 x 8 x 9 x 17 = 6120
// 8 = 8
// 8 x 9 = 72
// 8 x 9 x 17 = 1224
// Hence we got 6 even subarray multiplications.

// Sample Input-2:
// ---------------
// 3
// 5 7 11

// Sample Output-2:
// ----------------
// 0

// Explanation:
// ------------
// No subarrays which will give you even value after multiplication.

#include <bits/stdc++.h>
using namespace std;

int evenProd(vector<int> &arr)
{
    int i = 0, j = 0, c = 0, ans = 0;
    while (j < arr.size())
    {
        while (!c)
        {
            if (!(arr[j++] & 1))
                c++;
        }

        while (c)
        {
            ans += arr.size() - j + 1;
            if (!(arr[i++] & 1))
                c--;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int &i : arr)
        cin >> i;

    int ans = evenProd(arr);
    cout << ans;
}