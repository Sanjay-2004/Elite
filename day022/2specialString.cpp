// Students are given a special string consists of only'1' and '2'.
// and has to follow  the following rules:

// The string s is special because concatenating the number of contiguous
// occurrences of characters '1' and '2' generates the string s itself.
// The first few elements of s is s = "1221121221221121122……". If we group
// the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......"
// and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......".
// You can see that the occurrence sequence is s itself.

// Given an integer n, return the number of 1's in the first n number in the special string s.

// Input Format
// ------------
// Line1:An integer

// Output Format
// -------------
// An integer represents number of 1's in the first n number

// Sample Input-1:
// ---------------
// 6
// Sample Output-1:
// ----------------
// 3

// Explanation:
// ------------
// The first 6 elements of special string s is "122112" and
// it contains three 1's, so return 3.

// Sample Input-2:
// ---------------
// 1

// Sample Output-2:
// ----------------
// 1

#include <bits/stdc++.h>
using namespace std;

// void backTrack(int idx, int max, string& ans, int num){
//     // cout<<"backtrack "<<idx<<endl;
//     // cout<<"ans at idx "<<idx<<" "<<ans<<endl;
//     if(idx>max || ans.size()>max) return;
//     int n = ans[idx]-'0';
//     while(n--){
//         ans+=to_string(num);
//     }
//     if(num==1) num=2;
//     else num=1;
//     backTrack(idx+1, max, ans, num);
// }

string generateString(int n)
{
    if (n < 1)
        return "";
    string ans = "1";
    if (n == 1)
        return ans;
    ans += "22";

    int num = 1;
    for (int idx = 2; idx <= n; idx++)
    {
        if (ans.size() > n)
            break;
        int nOc = ans[idx] - '0';
        string temp;
        for (int i = 0; i < nOc; i++)
        {
            temp += to_string(num);
        }
        ans += temp;
        num = (num == 1) ? 2 : 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s = generateString(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            ans++;
    }
    cout << ans;
}