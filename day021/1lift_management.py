'''
In Dubai's Burj Khalifa, there is an elevator moves only in upwards direction, 
the elevator can carry N members.

The people are waiting for the elevator at different floors, made P requests, 
request[i] = [ num_people, enter_floor, exit_floor ], each request indicates, 
number of people to enter into elevator, entering floor number, 
exiting floor number.

Initially the elevator is empty.

Your task is to find and return true, iff it is possible to enter the people
into elevator and exit from elevator of all the requests made by the people.


Input Format:
-------------
Line-1 -> Two integers P and N, number of requests and number of members 
          can be carried by elevator.
Next N Lines -> three space separated integers, num_people, enter_floor, exit_floor.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
2 5
2 1 5
3 3 7

Sample Output-1:
----------------
true



Sample Input-2:
---------------
2 4
2 1 5
3 3 7

Sample Output-2:
----------------
false



Sample Input-3:
---------------
3 11
3 2 7
3 7 9
8 3 9

Sample Output-3:
----------------
true
'''

p, n = map(int,input().split())
last = 0

req = []

get_in = {}
get_out = {}

ans = True

for _ in range(p):
    ppl, st, en = map(int, input().split())
    if st not in get_in:
        get_in[st] = ppl
    else:
        get_in[st]+=ppl
    
    if en not in get_out:
        get_out[en] = ppl
    else:
        get_out[en]+=ppl
    last = max(last, en)
    
    
ppl = 0
for floor in range(last+1):
    if floor in get_in:
        ppl+=get_in[floor]
    if floor in get_out:
        ppl-=get_out[floor]
    if ppl>n:
        ans = False
        break
if ans:
    print("true")
else:
    print("false")