'''
Kittu playing a game, the game contains a panel of N cells.
Each cell in the panel is a number panel[i], 
Kittu will win when he reaches 0.

The rules to play the game are as follows:
	- Kittu's intital position is S.
	- When Kittu is at index i, he can move to position-(i + panel[i] ) or 
	position-(i - panel[i]).
	- Kittu cannot move outside the panel.
	- if he reaches any panel[i] has value 0, He wins.	

Your task to find that whether kittu wins or not.
if he wins print "true".
if there is no way to reach 0 then print "false".

NOTE: cell positions are numbered from 0 to N-1.
0<= panel[i] < N


Input Format:
-------------
Line-1: Two integers N and S, number of cells in the panel and 
		Kittu's initial position.
Line-2: N space separated integers.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
7 5
4 2 3 0 3 1 2

Sample Output-1:
----------------
true

Explanation: 
------------
All possible ways to reach at position 3 with value 0 are: 
position 5 -> position 4 -> position 1 -> position 3 
position 5 -> position 6 -> position 4 -> position 1 -> position 3 


Sample Input-2:
---------------
5 2
3 0 2 1 2

Sample Output-2:
----------------
false

'''
def out_of_bounds(cur, las):
    return cur<0 or cur>=las
    
def can_reach(arr,s, vis):
    if out_of_bounds(s,len(arr)):
        return False
    # print(s, arr[s])
    if arr[s] == 0:
        return True
    if vis[s]:
        return False
    vis[s] = True
    return can_reach(arr,s-arr[s], vis) or can_reach(arr,s+arr[s], vis)

n,s = map(int,input().split())

arr = list(map(int,input().split()))
vis = [False for _ in range(n)]

if can_reach(arr,s, vis):
    print("true")
else: print("false")



