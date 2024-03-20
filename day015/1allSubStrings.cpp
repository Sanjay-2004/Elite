// In a school, the students are given an array of strings words[]. Students have
// to find the longest string in words[] such that every prefix of it is also in words.

// For example, let words = ["a", "app", "ap","appl", "apply"]. The string "apply"
// has prefixes "ap","app","appl" and "a", all of which are in words.

// Your task is the find and return the longest string in words as described above.

// If there is more than one string with the same length, return the lexicographically
// smallest one, and if no string exists, return "".

// Input Format
// -------------
// Line1: string separated by spaces

// Output Format
// --------------
// string

// Sample Input-1:
// ---------------
// k kmi km kmit

// Sample Output-1:
// ----------------
// kmit

// Explanation:
// ------------
// "kmit" has prefixes "kmi", "km", "k" and all of them appear in words.

// Sample Input-2:
// ---------------
// t tanker tup tupl tu tuple tupla

// Sample Output-2:
// ----------------
// tupla

// Explanation:
// ------------
// Both "tuple" and "tupla" have all their prefixes in words.
// However, "tupla" is lexicographically smaller, so we return that.

// Sample Input-3:
// ---------------
// abc bc ab abcd

// Sample Output-3:
// ----------------
// ""

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isEnd;
    TrieNode *children[26];

    TrieNode()
    {
        isEnd = false;

        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insertString(string &s)
    {
        int k = 0;
        TrieNode *cur = root;

        for (int i = 0; i < s.length(); i++)
        {
            k = s[i] - 'a';
            if (cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->isEnd = true;
    }

    bool isSubstring(string &s)
    {
        int k = 0;
        TrieNode *cur = root;
        for (int i = 0; i < s.length(); i++)
        {
            k = s[i] - 'a';
            if (!(cur->children[k]->isEnd))
            {
                return false;
            }
            cur = cur->children[k];
        }
        if (cur == NULL || !cur->isEnd)
        {
            return false;
        }
        return true;
    }
};

string findLargestCommon(vector<string> &words)
{
    Trie *tree = new Trie();
    for (string word : words)
    {
        tree->insertString(word);
    }
    int ml = INT_MIN;
    string ans = "";
    for (string word : words)
    {
        if (tree->isSubstring(word))
        {
            if ((int)word.length() > ml)
            {
                ans = word;
                ml = word.length();
            }
            else if ((int)word.length() == ml && word < ans)
            {
                ans = word;
            }
        }
    }
    return ans;
}

int main()
{
    string sent;
    string ch;
    getline(cin, sent);
    stringstream ss(sent);
    vector<string> words;
    while (ss)
    {
        ss >> ch;
        words.push_back(ch);
    }
    words.pop_back();

    string ans = findLargestCommon(words);
    cout << ans;
}
