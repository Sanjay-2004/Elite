'''
A graduate at University of California (UoC) has to follow certain rules.

UoC offering K subjects, the subjects are indexed from 0 to K-1.
To complete the subjets, you have to follow the conditions, like 
condition[i]= [Xi, Yi], which specifies you must take the subject Xi 
before the subject Yi.

Conditions can be indirect, i.e., take course-A to take course-B, and take 
course-B to take course-C, then you have to take course-A to take course-C.

You are given total number of subjects, a list of C condition pairs and 
a list of Q queries where queries[i] = [Ai, Bi]. For the ith query, 
you should answer whether you have to take course Ai to take course Bi or not 
and return the answers as a boolean list answers[].

NOTE:
It is guaranteed that the course conditional graph continas no cycle.

Input Format:
-------------
Line-1: 3 space separated integers, N, C and Q
Next C lines: Two space separated integers, conditions[]
Next Q lines: Two space separated integers, conditions[]

Output Format:
--------------
Print Q boolean values as result.


Sample Input-1:
---------------
3 3 2
1 2
1 0
2 0
1 0
1 2

Sample Output-1:
----------------
true true


Sample Input-2:
---------------
5 4 3
0 1
0 2
1 4
1 3
0 2
1 3
1 2

Sample Output-2:
----------------
true true false

'''
n, c, q = map(int,input().split())


adj = [[] for _ in range(n)]

while c>0:
    a,b = map(int,input().split())
    temp = adj[b]
    adj[b].append(a)
    adj[b].extend(adj[a])
    c-=1

res=[]

while q>0:
    a,b = map(int,input().split())
    if a in adj[b]:
        res.append("true")
    else: res.append("false")
    q-=1
        
for r in res:
    print(r, end=" ")
    
