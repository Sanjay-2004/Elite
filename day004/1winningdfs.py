'''
Mansood Ali participated in a treasure-hunt conatins N boxes in it.
Each box is numbered from 0,1,2,3,...,N-1. 
All the boxes are intially locked with the passcodes, except Box-0.
The passcode is written in a envolope and marked with its concern box number.

Each box in the treasure hunt contains a list of envelopes, which has 
passcodes to open the other boxes. He can open the boxes in any order, 
but he has to start from box-0 intially.

The rule to win the treasure-hunt is to open all the boxes.
Your task is to find out, whether Mansood Ali win the treasure hunt or not.
If he win, print "Win", Otherwise, print "Lost"


Input Format:
-------------
Line-1: An integer, number of boxes.
Next N lines: space separated integers, box numbers.

Output Format:
--------------
Print a string value, Win or Lost


Sample Input-1:
---------------
5
1
2
3
4
3

Sample Output-1:
----------------
Win


Sample Input-2:
---------------
4
1 3
3 0 1
2
0

Sample Output-2:
----------------
Lost


-----------------------------
Write your python code below
-----------------------------

'''

def can_win(n, adj):
    vis = [False] * n
    queue = [0]
    while queue:
        temp = queue.pop()
        if vis[temp]: continue
        vis[temp] = True
        for ne in adj[temp]:
            if not vis[ne]: queue.append(ne)
    return all(vis)

n = int(input())
adj = []

for i in range(n):
    adj.append(list(map(int, input().split())))
    
print("Win") if can_win(n, adj) else print("Lost")