// In the present situation, most of the movies releasing in OTTs.
// The Showtime OTT in US, introduced a new offer for the customers,
// they can purchase either 1-day, 7-day, or 30-day subscription,
// and the cost is as follows price[0], price[1], price[2].

// The Subscription allows you to watch as many movies as you want with in subscribed days.
// For example:
// If you purchased, a 7-day subscription on day 5, then you can watch
// the movies for 7 days: day 5, 6, 7, 8, 9, 10 and 11.

// Your task is to find out the minimum cost, you spend to watch the movies
// in the given list of days .

// NOTE: Days are numbered from 1, 2, 3, ...365, in sorted order.

// Input Format:
// -------------
// Line 1: Space separated integer days[], list of days.
// Line 2: 3 space separated integer price[], cost of subscription.

// Output Format:
// --------------
// Print an integer, minimum cost.

// Sample Input-1:
// ---------------
// 1 4 6 7 8 20
// 2 7 15

// Sample Output-1:
// ----------------
// 11

// Explanation:
// ------------
// For example, here is a way to buy subscription, to watch the movies in given days:
// On day 1, buy a 1-day subscription for price[0] = $2, which cover day 1.
// On day 4, buy a 7-day subscription for price[1] = $7, which cover days 4, 5, ..., 10.
// On day 20, buy a 1-day subscription for price[0] = $2, which cover day 20.
// In total you spent $11.

// Sample Input-2:
// ---------------
// 1 2 3 4 5 6 7 8 9 10 30 31
// 2 7 15

// Sample Output-2:
// ----------------
// 17

// Explanation:
// ------------
// For example, here is a way to buy subscription, to watch the movies in given days:
// On day 1, buy a 30-day subscription for price[2] = $15, which cover days 1, 2, 3,....,30.
// On day 31, buy a 1-day subscription for price[0] = $2, which cover day 31.
// In total you spent $17.

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

vector<int> convertToVector(string s)
{
    stringstream ss(s);
    vector<int> res;
    int temp;
    while (ss)
    {
        ss >> temp;
        res.push_back(temp);
    }
    res.pop_back();
    return res;
}

int recursion(vector<int> &days, vector<int> &prices, int idx, int daysLeft)
{
    cout << idx << " " << daysLeft << endl;
    if (idx >= days.size())
        return 0;
    // if(prices[idx]<daysleft) return 1e6;
    int ans = INT_MAX;
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (days[idx + 1] < daysLeft)
            continue;
        cout << "prices[" << i << "] " << prices[i] << endl;
        ans = min(ans, recursion(days, prices, idx + 1, days[i] + mp[i] - 1) + prices[i]);
    }

    return ans;
}

int findMinCost(vector<int> &days, vector<int> &prices)
{
    int ans = recursion(days, prices, 0, 0);
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    vector<int> days = convertToVector(s);
    vector<int> prices(3);
    for (int &i : prices)
        cin >> i;
    mp[0] = 1;
    mp[1] = 7;
    mp[2] = 30;

    cout << findMinCost(days, prices);
}