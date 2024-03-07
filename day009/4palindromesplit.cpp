// In a school in Telangana students like to play with strings by splitting them.

// If they are given two strings s1 and s2 of the same length.
// They split both strings at the same choosen index , splitting s1 into
// two strings: prefix and suffix where s1 = prefix + suffix, and splitting s2
// into two strings: prefix1 and suffix1 where s2 = prefix1 + suffix1.

// Check if prefix + suffix1 or prefix1 + suffix forms a palindrome.

// For example, if s = "xyz", then "" + "xyz", "x" + "yz", "xy" + "z" ,
// and "xyz" + "" are valid splits.

// Return true if it is possible to form a palindrome string,
// otherwise return false.

// Notice that x + y denotes the concatenation of strings x and y.

// Example 1:
// ----------
// Input: s1 = "a", s2 = "b"
// Output: true
// Explaination: If either s1 or s2 are palindromes the answer is true
// since you can split in the following way:
// s1prefix = "", s1suffix = "a"
// s2prefix = "", s2suffix = "b"
// Then, s1prefix + s2suffix = "" + "b" = "b", which is a palindrome.

// Example 2:
// -----------
// Input: a = "zdfgh", b = "zgecd"
// Output: false

// Example 3:
// ----------
// Input: s1 = "vmbdge", s2 = "kjabmv"
// Output: true
// Explaination: Split them at index 3:
// prefix = "vmb", suffix = "dge"
// prefix1 = "kja", suffix1 = "bmv"
// Then, prefix + suffix1 = "vmb" + "bmv" = "vmbbmv", which is a palindrom

// Sample Input-1:
// ---------------
// a b----> two strings

// Sample Output-1:
// ----------------
// true

// Sample Input-2:
// ---------------
// vmbdge kjabmv   ------->two strings

// Sample Output-2:
// ----------------
// true

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

bool canSplit(string s1, string s2)
{
    int i = 0, j = s2.length() - 1;
    while (s1[i] == s2[j] && i++ <= j--)
        ;

    if (isPalindrome(s1, i, j) || isPalindrome(s2, i, j))
        return true;
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (canSplit(s1, s2) || canSplit(s2, s1))
        cout << "true";
    else
        cout << "false";
}