// Vihaar is working with strings.
// He is given two strings A and B, and another string T,
// where the length of A and B is same.

// You can find the relative groups of letters from A and B,
// using the following rule set:
// - Equality rule: 'p' == 'p'
// - Symmetric rule: 'p' == 'q' is same as 'q' == 'p'
// - Transitive rule: 'p' == 'q' and 'q' == 'r' indicates 'p' == 'r'.

// Vihaar has to form the relatively smallest string of T,
// using the relative groups of letters.

// For example, if A ="pqr" and B = "rst" ,
// then we have 'p' == 'r', 'q' == 's', 'r' == 't' .

// The relatives groups formed using above rule set are as follows:
// [p, r, t] and [q,s] and  String T ="tts", then relatively smallest string is "ppq".

// You will be given the strings A , B and T.
// Your task is to help Vihaar to find the relatively smallest string of T.

// Input Format:
// -------------
// Three space separated strings, A , B and T

// Output Format:
// --------------
// Print a string, relatively smallest string of T.

// Sample Input-1:
// ---------------
// kmit ngit mgit

// Sample Output-1:
// ----------------
// ggit

// Explanation:
// ------------
// The relative groups using A nd B are [k, n], [m, g], [i], [t] and
// the relatively smallest string of T is "ggit"

// Sample Input-2:
// ---------------
// attitude progress apriori

// Sample Output-2:
// ----------------
// aaogoog

// Explanation:
// ------------
// The relative groups using A nd B are [a, p], [t, r, o], [i, g] and [u, e, d, s]
// the relatively smallest string of T is "aaogoog"

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        // size.resize(n, 1);
    }

    int findParent(int v)
    {
        if (parent[v] == v)
            return v;
        else
            return parent[v] = findParent(parent[v]);
    }

    void unionSet(int v1, int v2)
    {
        // cout<<v1<<" "<<v2<<endl;
        int p1 = findParent(v1);
        int p2 = findParent(v2);
        // cout<<p1<<" "<<p2<<endl;
        if (p1 == p2)
            return;
        parent[max(p1, p2)] = min(p1, p2);
    }
};

int main()
{
    string a, b, c, word;
    getline(cin, word);

    istringstream ss(word);
    ss >> a >> b >> c;

    DSU ds(26);

    for (int i = 0; i < a.size(); i++)
    {
        char c1 = a[i];
        char c2 = b[i];
        ds.unionSet(c1 - 'a', c2 - 'a');
    }
    string ans = "";
    for (int i = 0; i < c.size(); i++)
    {
        char ch = c[i];
        int p = ds.findParent(ch - 'a');
        // cout<<p<<endl;
        ans += (char)(p + 'a');
    }
    cout << ans;
}
