'''
The heights of the students of two classes are given as h1[] and h2[],
the student count of the classes are same. The task is to find 
the sum of the product of heights of these two classes.

For example, if h1 = [1,2,3,4] and h2 = [5,2,3,1], the sum of products would be
1*5 + 2*2 + 3*3 + 4*1 = 22.

You are given two lists h1 and h2 of length n, return the minimum product sum 
if you are allowed to rearrange the order of the elements in h1. 

Sample Input-1:
---------------
4
5 3 4 2
4 2 2 5

Sampe Output-1:
---------------
40

Explanation:
------------
We can rearrange h1 to become [3,5,4,2]. 
The sum of products of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.


Sample Input-2:
---------------
5
2 1 4 5 7
3 2 4 8 6

Sampe Output-2:
---------------
65

Explanation:
------------
We can rearrange h1 to become [5,7,4,1,2]. 
The product sum of [5,7,4,1,2] and [3,2,4,8,6] is 
5*3 + 7*2 + 4*4 + 1*8 + 2*6 = 65.

'''

n = int(input())
h1 = list(map(int, input().split()))
h2 = list(map(int, input().split()))

h1.sort()
h2.sort(reverse = True)

# print(h1, h2)

ans = 0

for i in range(n):
    # print(h1[i], h2[i], h1[i]*h2[i])
    ans+=(h1[i]*h2[i])

print(ans)