// To get the admission into 6th standard in a reputed school in Hyderabad,
// conducted an entrance test. one of the questions in the test was

// There was a sequence of characters(String) given, student has to check
// in given String how many substrings are same as reverse of it (palindromic).

// Input Format:
// -------------
// Read a String.

// Output Format:
// --------------
// Print number of palindromic substrings of given string.

// Sample Input-1:
// ---------------
// pqrs

// Sample Output-1:
// ----------------
// 4

// Explanation:
// ------------
// "p", "q", "r", "s" are palindromic substrings of given string.

// Sample Input-2:
// ---------------
// pppp

// Sample Output-2:
// ----------------
// 10

// Explanation:
// ------------
// "p", "p", "p", "p", "pp", "ppp", "pppp", "pp", "ppp", "pp"  are
// palindromic substrings of given string.

#include <bits/stdc++.h>
using namespace std;

int findPalindromicSubstrings(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < s.length())
        {
            if (s[l--] == s[r++])
            {
                ans++;
            }
            else
                break;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < s.length())
        {
            if (s[l--] == s[r++])
            {
                ans++;
            }
            else
                break;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int ans = findPalindromicSubstrings(s);

    cout << ans;
}