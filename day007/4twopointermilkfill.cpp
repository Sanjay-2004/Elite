// Sam and Lam want to distribute milk to n houses in their area.The houses are
//         arranged in a row with label from 0 to n -
//     1 from left to right,
//     where the i - th house is located at x = i.

//                                              Each house needs a specific amount of milk.Sam and
//                                              Lam have a their own milk and initially full.They distribute the milk in the following way : -Sam gives milk to the houses in order from left to right,
//                                          starting
//                                              from the 0th house.Lam gives milk in order from right to left,
//                                          starting
//                                              from(n - 1) th house.

//                                              - They begin distributing the milk simultaneously.It takes the same amount
//                                                of time to give milk to each house regardless of how much milk it needs.

//                                              - Sam / Lam must distribute milk,
//                                          if they have enough in their can to fully
//                                          give it.Otherwise,
//                                          they first refill their can(instantaneously), then give the milk to the house.In case both Sam and Lam reach the same house,
//                                          the one with more milk currently in their milk can should give milk to the
//                                          house.If they have the same amount of milk,
//                                          then Sam should give the milk.

//                                              Given array of house needs starting from 0 to N
//                                              - 1 integers,
//                                          where house[i] is the amount of milk the i - th house needs, and two integers capA and capB representing the capacities of Sam 's and Lam' s milk cans respectively.Return the number of times they have to refill to distribute milk to all the houses.

//                                                                                                           Input Format:
// -------------
// Line-1: 3 space separarted integers, indiactes N, CapA and capB.
// Line-2: N space separated integers, house[].

// Output Format:
// --------------
// Print an integer result.

// Sample Input:
// -------------
// 4 5 5
// 5 3 3 4

// Sample Output:
// --------------
// 2

// Explanation:
// ------------
// - Initially, Sam and Lam have 5 units of milk each in their cans.
// - Sam gives milk to house 0, Lam gives to house 3.
// - Sam and Lam now have 0 units and 1 unit of milk respectively.
// - Sam has to refil can for house 1, and Lam also does not have enough milk
// for house 3, so he refills his can. So, the total number of times they have
// to refill  0 + 0 + 1 + 1 = 2.

// Sample Input:
// -------------
// 3 9 7
// 4 5 2

// Sample Output:
// --------------
// 0

#include <bits/stdc++.h>
using namespace std;

int findRefills(vector<int> &arr, int ca, int cb)
{
    int ans = 0;
    int tca = ca, tcb = cb;
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (tca < arr[i])
        {
            ans++;
            tca = ca - arr[i];
        }
        else
            tca -= arr[i];
        i++;

        if (tcb < arr[j])
        {
            ans++;
            tcb = cb - arr[j];
        }
        else
            tcb -= arr[j];
        j--;
    }
    if (i == j)
    {
        if (tca >= tcb)
        {
            if (tca < arr[i])
            {
                ans++;
                tca = ca - arr[i];
            }
            else
                tca -= arr[i];
        }
        else
        {
            if (tcb < arr[j])
            {
                ans++;
                tcb = cb - arr[j];
            }
            else
                tcb -= arr[j];
        }
    }
    return ans;
}

int main()
{
    int n, cA, cB;
    cin >> n >> cA >> cB;

    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    cout << findRefills(arr, cA, cB);
}