'''
There are n students in a line. You are given an integer array heights of 
size n that represents the heights of the students in the line.

The blackboard is to the right of the students. A student has a blackboard
view if the student can see the blackboard without obstructions.
Formally, a student has a blackboard view if all the studentss to his 
right have a smaller height.

Return a list of indices (0-indexed) of students that have a blackboard
view, sorted in increasing order

Input Format
------------
Line1: An integer size of the array
Line2: Space separated integers of array
  
Output Format
-------------
Resultant integer array in ascending order 


 
Example 1:
Input:  5
        heights = [5,4,3,2,1]
Output: [0,1,2,3,4]
Explanation: All the students has the blackboard view.

Example 2:
Input:  6
        heights = [1,5,3,4,2,6]
Output: [5]
Explanation: Only building 5 has the blackboard view.

'''

def find_right_view(heights):
    ans = []
    curmax = heights[len(heights)-1]-1

    for i in range(len(heights)-1,-1,-1):
        if heights[i]>curmax:
            ans.append(i)
            curmax = heights[i]
    return ans[::-1]

n = int(input())
heights = list(map(int, input().split()))

ans = find_right_view(heights)
print(ans)
