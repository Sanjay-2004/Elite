'''
The laser show at the Lumbini Park is something not to be missed.
But, as per govt rule they have to follow COVID-19 restrictions.
The management planning to guide the audience to sit in the seats
that maximizes the distance to the closest person, in order to
practice the social distance in the auditorium.

Please help usher to guide the audience to sit in a seat by following few rules:

- There are N seats in a single row, seats are numbered from 0 to N-1.
- Maximize the distance from person to the closest person.
- If there are multiple seats with similar distance, they sit in the seat with the lowest number.
- First person always sit in seat number 0.
- If a person leaves the auditorium from a seat, please consider that the seat is vacant

Create a class Auditorium and two functions in it.
1. int seat(): represent the seat number of audience to sit.
2. void leave(int s): person leaves the auditorium from a seat number 's'.

Input Format:
----------------
Line-1 -> two integers N and P, Number of seats N, Number of Operations P
P lines of input -> each line contains funtion number and parameter list (if required).

Output Format:
------------------
Print the alloted seat numbers in one line as output.


Sample Input-1:
-------------------
10 6
1
1
1
1
2 4
1

Sample Output-1:
---------------------
0 9 4 2 5

NOTE:
-----
In the sample input:
    - option 1 indicates, calling "int seat()" method.
    - option 2 indicates, calling "void leave(seat_num)" method.

'''

class Seats:
    def __init__(self, n):
        self.n = n
        self.seats = [0] * n
    def seat(self):
        if not self.seats[0]:
            self.seats[0] = 1
            return 0
        elif not self.seats[n-1]:
            self.seats[n-1] = 1
            return n-1
        else:
            max_l, max_r = -1,-1
            l=0
            d=0
            for r, st in enumerate(self.seats):
                if st:
                    # print(l, r)
                    dis = (r-l)//2
                    if dis>d:
                        d = dis
                        max_l = l
                        max_r = r
                    l = r
            # print(max_l, max_r) 
            # print("idx", (max_r+max_l)//2)
        self.seats[(max_r+max_l)//2] = 1
        return (max_r+max_l)//2
    
    def leave(self, st):
        # print(st)
        self.seats[st] = 0
        
n, p = map(int,input().split())
s = Seats(n)
ans = []

for i in range(p):
    op = list(map(int, input().split()))
    if len(op)==1:
        # print("seating")
        ans.append(s.seat())
    else:
        # print("removing")
        s.leave(op[1])

for i in ans:
    print(i, end=" ")


