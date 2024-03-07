// AlphaCipher is a string formed from another string by rearranging its letters

// You are given a string S.
// Your task is to check, can any one of the AlphaCipher is a palindrome or not.

// Input Format:
// -------------
// A string S

// Output Format:
// --------------
// Print a boolean value.

// Sample Input-1:
// ---------------
// carrace

// Sample Output-1:
// ----------------
// true

// Sample Input-2:
// ---------------
// code

// Sample Output-2:
// ----------------
// false

#include <bits/stdc++.h>
using namespace std;

bool isPalinBit(string s)
{
    int ans = 0;
    int oc = 0;
    for (char c : s)
    {
        ans ^= (1 << (c - 'a'));
    }
    while (ans)
    {
        if (ans & 1)
            oc++;
        ans >>= 1;
    }
    return oc <= 1;
}

bool isPalinBit2(string s)
{
    int bitVector = 0;
    for (char c : s)
    {
        int mask = 1 << (c - 'a');
        bitVector ^= mask;
    }

    return (bitVector & (bitVector - 1)) == 0;
}

int main()
{
    string s;
    cin >> s;
    if (isPalinBit(s))
        cout << "true";
    else
        cout << "false";
}