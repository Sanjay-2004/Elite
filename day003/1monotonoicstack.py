'''
Prabhath is working on words.  
He used to take out every letter that was repeated in the word. 
A word W is given to Prabhath. 
His objective is to eliminate every duplicate letter from W 
such that the resultant word R contains every unique letter from W
and did not contain any duplicate letters. 
And R should be at the top of the dictionary order.

NOTE:
-----
He is not allowed to shuffle the relative order 
of the letters of the word W to form the word R.

Input Format:
-------------
A String, the word W.

Output Format:
--------------
Print a String, resultant word R.


Sample Input-1:
---------------
cbadccb

Sample Output-1:
----------------
adcb


Sample Input-2:
---------------
silicosis

Sample Output-2:
----------------
ilcos

'''

word = input()
st = []
mp = {char: word.count(char) for char in set(word)}

for c in word:
    if c in st:
        mp[c] -= 1
        continue

    while st and st[-1] > c and mp[st[-1]] > 0:
        st.pop()

    st.append(c)
    mp[c] -= 1

print(''.join(st))
        

    
    
    
    