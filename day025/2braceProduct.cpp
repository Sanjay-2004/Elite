// Subodh is interested in playing with Strings,
// For a given String 'S', Subodh applies some rules to find the value of 'S'.
// The rules are as follows:
// 	- If it is a balanced [] has value 1
// 	- XY has value X + Y , where X and Y are balanced [] strings.
// 	- [Z] has score 2 * Z , where Z is a balanced parentheses string.

// Find out the value of given String and print it.

// Note: All the given strings are balanced

// Input Format:
// -------------
// A String contains only '[', ']'

// Output Format:
// --------------
// Print an integer as result.

// Sample Input-1:
// -------------------
// []

// Sample Output-1:
// ----------------
// 1

// Sample Input-2:
// ---------------
// [[]]

// Sample Output-2:
// ----------------
// 2

// Sample Input-3:
// ---------------
// [ [] [ [] ] ]

// Sample Output-3:
// ----------------
// 6

#include <bits/stdc++.h>
using namespace std;

int findPScore(string s)
{
    stack<string> st;

    for (char c : s)
    {
        if (c == '[')
        {
            st.push(string(1, c));
        }
        else
        {
            // cout<<st.top();
            int temp = 0;
            if (st.top() == "[")
            {
                // cout<<"Part 1\n";
                st.pop();
                st.push("1");
            }
            else
            {
                // cout<<"Part 2\n";
                while (st.top() != "[")
                {
                    temp += stoi(st.top());
                    st.pop();
                }
                st.pop();
                st.push(to_string(temp * 2));
            }
        }
    }
    int ans = 0;
    while (st.size())
    {
        ans += stoi(st.top());
        st.pop();
    }
    return ans;
}

signed main()
{
    string s;
    cin >> s;

    int ans = findPScore(s);
    cout << ans;
}