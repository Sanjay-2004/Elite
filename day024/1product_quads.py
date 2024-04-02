'''
In a Mathematics class students are given a list  which are  distinct  and 
positive integers. Students should do the calculation and return 
the number of quadraples (p, q, r, s) such that p * q = r * s
where p, q, r, and s are elements of list, and p != q != r != s.

Input Format
-------------
Line-1: An integer N, number of elements in the list
Line-2: N space separated integers, the list[]

Output Format
-------------
An integer which is no of quadraples


Sample Input-1:
---------------
4
2 3 4 6

Sample Output-1:
----------------
8

Explanation:
------------
There are 8 valid quadraples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)


Sample Input:
-------------
5
1 2 4 8 16

Sample Output:
--------------
24

Explanation:
------------
There are 24 valid quadraples:
(1,16,2,8) , (1,16,8,2) , (16,1,2,8) , (16,1,8,2)
(2,8,1,16) , (2,8,16,1) , (8,2,1,16) , (8,2,16,1)
(1,8,4,2) , (1,8,2,4) , (8,1,4,2) , (8,1,2,4)
(4,2,1,8) , (4,2,8,1) , (2,4,1,8) , (2,4,8,1)
(2,16,4,8) , (2,16,8,4) , (16,2,4,8) , (16,2,8,4)
(4,8,2,16) , (4,8,16,2) , (8,4,2,16) , (8,4,16,2)
'''

def find_cases(nums: list, n: int) -> int:
    ans = 0
    mp = {}
    for i in range(n):
        for j in range(i+1, n):
            p = nums[i] * nums[j]
            if(p not in mp): mp[p] = 0
            mp[p]+=1
    
    for k in mp:
        # print(k, mp[k], "adding: ", 4*mp[k]*(mp[k]-1))
        ans+=(4*mp[k]* (mp[k]-1))
    
    return ans

n = int(input())
nums = list(map(int, input().split()))

ans = find_cases(nums, n)

print(ans)
