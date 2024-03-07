'''
There is a String S given to a student of even length N whose indexes start from 0.
The number of open brackets '[' and close brackets ']' in the string S are equal.

Students have to balance the string S. The string is balanced if and only if
        -It is the empty string, or
        -It can be written as XY, where both X and Y are balanced strings, or
        -It can be written as [Z], where Z is a balanced string.
        -You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make string balanced.


Input Format:
-------------
Line-1: A string S, contains open '[' and close ']' brackets

Output Format:
--------------
An integer result, number of swaps


Sample Input-1:
---------------
][

Sample Output-1:
----------------
1

Explanation:
------------
String is balanced by swapping index 0 with index 1.
The resultant string is "[]".


Sample Input-2:
---------------
[][][][][]

Sample Output-2:
----------------
0

Explanation:
------------
The string is already balanced


Sample Input-3:
---------------
]]][[[[]

Sample Output-3:
----------------
2

Explanation:
------------
You can do the following steps to make the string balanced:
- Swap index 0 with index 4. s = "[]][][[]".
- Swap index 1 with index 5. s = "[[][]][]".
The resulting string is "[[][]][]".



'''

s = input()
st =[]
cl=0
op=0
for c in s:
    if not st:
        if c=='[': op+=1
        else: cl+=1
        st.append(c)
        continue
    if c==']' and st[-1]=='[':
        op-=1
        st.pop()
    elif c==']':
        cl+=1
        st.append(c)
    elif c=='[':
        op+=1
        st.append(c)
        
if not st:
    print(0)
else:
    print((cl+1)//2)
    
    