// A transitive law is "If a == b and b == c, then a == c"
// Which also says "If a == b and b != c, then a != c"

// You will be given a list of strings relations[], i.e, like p==q or p!=q.
// Your task is to find out whether all the relations follow the transitive law or not.
// If all of them followed return true, otherwise return false.

// Input Format:
// -------------
// Space separated strnigs, list of relations

// Output Format:
// --------------
// Print a boolean value, whether transitive law is obeyed or not.

// Sample Input-1:
// ---------------
// a==b c==d c!=e e==f

// Sample Output-1:
// ----------------
// true

// Sample Input-2:
// ---------------
// a==b b!=c c==a

// Sample Output-2:
// ----------------
// false

// Sample Input-3:
// ---------------
// a==b b==c c!=d d!=e f==g g!=d

// Sample Output-3:
// ----------------
// true
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int upar_u = findUPar(u), upar_v = findUPar(v);

        if (u == v)
            return;

        if (rank[upar_u] >= rank[upar_v])
        {
            parent[upar_v] = upar_u;
        }

        else
        {
            parent[upar_u] = upar_v;
        }
    }
};
int main()
{
    DisjointSet ds(26);
    string s;
    getline(cin, s);
    stringstream str(s);
    string s1, prev = "";
    vector<string> eqs;
    while (1)
    {
        getline(str, s1, ' ');
        if (s1 == prev)
            break;
        eqs.push_back(s1);
        prev = s1;
    }
    int flag = 0;
    for (auto st : eqs)
    {
        if (st[1] == '!')
            continue;

        ds.unionByRank(st[0] - 'a', st[3] - 'a');
    }

    for (auto st : eqs)
    {
        if (st[1] == '!')
        {
            if (ds.findUPar(st[0] - 'a') == ds.findUPar(st[3] - 'a'))
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
        cout << "false";

    else
        cout << "true";
}