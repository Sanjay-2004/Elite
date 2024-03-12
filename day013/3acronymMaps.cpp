// Ananth interested in creating the acronyms for any word. The definition
// of acronym is another word with a concatenation of its first letter,
// the number of letters between the first and last letter, and its last letter.

// If a word has only two characters, then it is an acronym of itself.

// Examples:
//     - Acronym of 'fog' is f1g'.
//     - Acronym of 'another' is 'a5r'.
//     - Acronym of 'ab' is 'ab'.

// You are given a list of vocabulary, and another list of words.
// Your task is to check,each word with the vocabulary and
// return "true" if atleast one of the following rules satisfied:
// 1. acronym of the word should not match with any of the acronyms of vocabulary
// 2. if acronym of the word matches with any of the acronyms of vocabulary
// 'the word' and matching words in vocabulary should be same.

// Otherwise, return 'false'.

// Input Format:
// -------------
// Line-1: Space separated strings, vocabulary[]
// Line-2: Space separated strings, words[]

// Output Format:
// --------------
// Print N boolean values, where N = words.length

// Sample Input-1:
// ---------------
// cool bell cool coir move more mike
// cool char move

// Sample Output-1:
// ----------------
// true false false

#include <bits/stdc++.h>
using namespace std;

string findShort(string s)
{
    string ans = "";
    ans += s[0];
    int m = s.size() - 2;
    ans += to_string(m);
    ans += s[s.size() - 1];
    return ans;
}

vector<bool> findAcronyms(vector<string> &vocabulary, vector<string> &words)
{
    vector<bool> ans;
    unordered_map<string, string> mp;

    for (string s : vocabulary)
    {
        string shortForm = findShort(s);
        if (mp.count(shortForm) && (mp[shortForm] != s || mp[shortForm] == "false"))
        {
            mp[shortForm] = "false";
        }
        else
            mp[shortForm] = s;
    }

    for (string s : words)
    {
        string shortForm = findShort(s);
        if (mp.count(shortForm))
        {
            if (mp[shortForm] == s)
            {
                ans.push_back(true);
            }
            else
                ans.push_back(false);
        }
        else
        {
            ans.push_back(true);
        }
    }

    return ans;
}

int main()
{
    string v;
    getline(cin, v);
    stringstream ss(v);
    vector<string> vocab;
    string ch;
    while (ss)
    {
        ss >> ch;
        vocab.push_back(ch);
    }
    vocab.pop_back();

    getline(cin, v);
    stringstream ss1(v);
    vector<string> words;
    while (ss1)
    {
        ss1 >> ch;
        words.push_back(ch);
    }
    words.pop_back();

    vector<bool> ans = findAcronyms(vocab, words);
    for (auto x : ans)
    {
        if (x)
            cout << "true ";
        else
            cout << "false ";
    }
}