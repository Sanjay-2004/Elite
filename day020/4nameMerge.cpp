// Venkat wants to create a unique name for his child, to do that he is referring
// two names, one is traditonal name(TN) and other is modern name(MN).

// He is planning to create unique name(UN), using the following ways:
//     - if traditional name TN is non empty, then add the first letter L of TN
//     to unique name UN and remove the letter L from traditional name TN
// 	e.g., if TN = "havi" and UN="anvika", then after adding L to UN and remove L
// 	from TN, the names updated as UN="hanvika", TN="avi".

//    - if modern name MN is non empty, then add the first letter L of MN
//     to unique name UN and remove the letter L from modern name MN
//     e.g., if MN = "ram" and UN="ao", then after adding L to UN and remove L
// 	from MN, the names updated as UN="rao", MN="am".

// You are given two names, TN and MN,
// Your task is to help venkat to generate the unique name for his child,
// and the name should be largest in the dictionary order.

// For example, "kmit" is larger than "kmec", as third letter is greater in "kmit".

// Input Format:
// -------------
// Two space separated names, TN and MN.

// Output Format:
// --------------
// Print a string, the laregst unique name possible.

// Sample Input-1:
// ---------------
// sudha vivid

// Sample Output-1:
// ----------------
// vsuividhda

// Sample Input-2:
// ---------------
// appa banana

// Sample Output-2:
// ----------------
// bappananaa

#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string tn, mn;
    cin >> tn >> mn;
    string un = "";
    int i = 0, j = 0;
    while (i < tn.size() && j < mn.size())
    {
        if (tn.substr(i, tn.size() - i + 1) >= mn.substr(j, mn.size() - j + 1))
        {
            // cout<<"i: "<<tn[i]<<endl;
            un += tn[i++];
        }
        else
        {
            // cout<<"j: "<<mn[j]<<endl;
            un += mn[j++];
        }
    }
    while (i < tn.size())
        un += tn[i++];
    while (j < mn.size())
        un += mn[j++];
    cout << un;
}