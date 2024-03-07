'''
Murali playing a mobile game, Blast the letters.

In the game he is given a word W and value R.
Murali has to perform the blasting operation as follows:
	- He has to blast the mimeograph M of length R in W, 
	  a mimeograph is a string such that each letter in it should be same.
	- After blasting the mimeograph, the rest of the string on its
	  left side and right side, concatenated together.

Murali has to perform the blasting operation repeatedly, 
until no more blasting is possible. Your task is to return 
the final string after all the blast operations have been done.

Input Format:
-------------
Line-1: A string and an integer, W and R.

Output Format:
--------------
Print a string, the final string after all the blast operations have been done.


Sample Input-1:
--------------- 
ababbaaab 3

Sample Output-1:
----------------
aba


Sample Input-2:
--------------- 
caaabbbaacdddd 2

Sample Output-2:
----------------
cabc

'''

word, val = input().split()
val = int(val)

st = []

stc=[]

for c in word:
    if len(st)==0:
        st.append(c)
        stc.append([c,1])
        continue
    if c==st[-1]:
        st.append(c)
        stc[-1][-1]+=1
    else:
        st.append(c)
        stc.append([c,1])
    
    if stc[-1][-1]==val:
        for i in range(val):
            st.pop()
        stc.pop()
        
print("".join(st))



