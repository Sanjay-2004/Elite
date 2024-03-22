// Clavius, the person who suggested grouping of data using brackets.
// He has suggested that the group of brackets should be Well-Formed.

// A string is said to be Well-Formed, if:
//     - The string is empty.
//     - The string can be written as MN, (M is appended to N),
//       where M and N are Well-Formed Strings, or
//     - The string can be written as {M}, where M is Well-Formed string.

// You will be given an integer N. Your task is to return the list of all
// Well-Formed strings of length 2*N.

// Input Format:
// -------------
// An integer N.

// Output Format:
// --------------
// Print the list of well-formed strings.

// Sample Input-1:
// ---------------
// 3

// Sample Output-1:
// ----------------
// [{{{}}},{{}{}},{{}}{},{}{{}},{}{}{}]

// Sample Input-2:
// ---------------
// 1

// Sample Output-2:
// ----------------
// [{}]

#include <bits/stdc++.h>
using namespace std;

void backTrack(int n, int open, int closed, string &output, vector<string> &ans)
{
    if (output.size() == n << 1)
    {
        ans.push_back(output);
        return;
    }
    if (open < n)
    {
        output += '{';
        backTrack(n, open + 1, closed, output, ans);
        output.pop_back();
    }
    if (closed < open)
    {
        output += '}';
        backTrack(n, open, closed + 1, output, ans);
        output.pop_back();
    }
}
vector<string> generateBrackets(int n)
{
    if (n == 1)
    {
        return {"{}"};
    }
    vector<string> ans;
    string output = "";
    backTrack(n, 0, 0, output, ans);
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    vector<string> ans = generateBrackets(n);
    // for(int i=0;i<ans.size();i++){
    //     if(!i)
    //         cout<<"[";
    //     cout<<ans[i];

    //     if(i==ans.size()-1)
    //         cout<<"]"<<endl;
    //     else
    //         cout<<",";
    // }
    for (auto &s : ans)
    {
        cout << s << " ";
    }
}