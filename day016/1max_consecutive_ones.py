'''
Given a binary array nums and an integer k, return the maximum number 
of consecutive 1's in the array if you can flip at most k 0's.

In a class students are given series of zeroes and ones and an integer 'k'. They have to return
maximum number of consecutive ones in the series if they can flip at most 'k' zeroes


Input Format
------------
Line1: An integer represents number of zeroes and ones
Line2: space separated integers which are zeroes and ones
Line3: An integer represents no of zeroes which can be flipped

Output Format
-------------
An integer represents maximum number of consecutive ones


Sample Input1:
--------------
11
1 1 1 0 0 0 1 1 1 1 0
2

Sample Output2:
---------------
6

Explanation:
------------
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Sample Input2:
--------------
19
0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
3

Sample Output2:
---------------
10

Explanation:
------------
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

'''

n = int(input())
arr = list(map(int, input().split()))
k = int(input())

l,ans = 0,0

for r, e in enumerate(arr):
    k-=1-e

    if k<0:
        k+=1-arr[l]
        l+=1
    else:
        ans = max(ans, r-l+1)

print(ans)
