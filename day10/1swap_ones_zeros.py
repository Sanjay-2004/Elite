'''
In an international cricket stadium before starting of the game
players stand in a row with tshirt numbers 0's and 1's  randomly.

But the players with tshirt-number 1 wants to stand together.
Your task is to print the least number of interchages of places to group all
players with tshirt number 1.

Input Format:
-------------
Line-1: Read an integer R, number of players.
Line-2: Read R tshirt-numbers standing in a row.

Output Format:
--------------
Print an integer result.


Sample Input-1
--------------
5
1 0 1 0 1

Sample Output-1
---------------
1

Explanation
-----------
There are 3 ways to group all 1's together
1 1 1 0 0  after 1 interchange
0 1 1 1 0  after 2 interchanges
0 0 1 1 1  after 1 interchange
The least is 1.


Sample Input-2
--------------
7
1 0 1 0 1 0 1

Sample Output-2
---------------
2

Explanation
-----------
There are 4 ways to group all 1's together
1 1 1 1 0 0 0  after 2 interchanges
0 0 0 1 1 1 1  after 2 interchanges
0 1 1 1 1 0 0  after 2 interchanges
0 0 1 1 1 1 0  after 2 interchanges 
The minimum is 2.
 

Sample Input-3
--------------
6
0 1 0 0 0 0

Sample Output-3
---------------
0

Explanation
-----------
No interchange required.

'''

def minimum_rearrangements(order):
    i,j=0,len(order)-1
    while order[i]!=1:
        i+=1
    ans=0
    while i<j:
        while order[i]==1: i+=1
        while order[j]==0: j-=1
        if i>j: break
        if order[i]==0 and order[j]==1:
            order[i], order[j] = order[j], order[i]
            ans+=1
    return ans
        
    


n = int(input())
order = list(map(int, input().split()))

ans = minimum_rearrangements(order)
print(ans)
