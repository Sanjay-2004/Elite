'''
In a school, The class teacher assigned 
a task to the CR(class representative) of a class, 
Given an integer array choclates[] where choclates[i] denotes the color of 
the ith choclate.

Teacher instructed to the CR to distribute the choclates by 
sharing p continuous(consecutive) choclates among the students.
But CR wants to preserve as many colors of choclates as possible.

Print the max count of unique colors of choclates that CR preserved 
after distribution. 


Input Format:
-------------
Line-1: Two integers L and p (space separated), L number of choclates[], and p value.
Line-2: L number of space separated colors of choclates.

Output Format:
--------------
Print the max count of unique colors.



Sample Input-1:
---------------
6 3
3 3 4 5 4 1

Sample Output-1:
----------------
3

Explanation:
------------
CR can distribute choclates from index 0 to 2 with colors 3,3,4
Now remaining unique colors are 5,4,1 hence print 3.


Sample Input-2:
---------------
6 2
9 9 9 9 7 7

Sample Output-2:
----------------
2

Explanation:
------------
CR can distribute choclates from index 3 to 4 with colors 9,7.
The preserved choclates are 9,9,9,7.
unique colors are 9,7 hence print 2.

Else, CR can distribute choclates with colors 9,9
and preserve the choclates with colors 9,9,7,7.


Sample Input-3:
---------------
3 0
4 6 8

Sample Output-3:
----------------
3

Explanation:
------------
CR do not have to distribute any choclates.
can preserve the choclates with colors 4,6,8.
unique colors are 4,6,8 hence print 3.
'''

def find_choco(chocolates, ch):
    freq = {}
    for i in chocolates:
        freq[i] = chocolates.count(i)
    i,j=0,0
    while j<ch:
        freq[chocolates[j]]-=1
        if freq[chocolates[j]]==0:
            del(freq[chocolates[j]])
        j+=1
    ans = len(freq)
    while j<len(chocolates):
        if chocolates[i] not in freq: 
            freq[chocolates[i]] = 0
        freq[chocolates[i]]+=1
        i+=1
        freq[chocolates[j]]-=1
        if freq[chocolates[j]]==0:
            del(freq[chocolates[j]])
        j+=1
        ans = max(ans, len(freq))
    return ans
        
    

n, c = map(int, input().split())
choco = list(map(int, input().split()))

print(find_choco(choco, c))