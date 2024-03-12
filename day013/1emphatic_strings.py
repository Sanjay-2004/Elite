'''
"Emphatic Pronunciation" of a given word is where we take the word and
replicate some of the letter to emphasize their impact.

Instead of saying 'oh my god', someone may say "ohhh myyy goddd", 
We define emphatic pronunciation of a word, which is derived by replicating 
a group (or single) of letters in the original word. 

So that the replicated group is atleast 3 characters or more and 
greater than or equal to size of original group. 
For example Good -> Goood is an emphatic pronunciation,
but Goodd is not because in Goodd the 'd' are only occuring twice consecutively.
 
In the question you are given the "Emphatic pronunciation" word, 
you have to findout how many words can legal result in the 
"emphatic pronunciation" word.

Input Format:
-------------
Line-1 -> A String contains a single word, Emphatic Pronunciation word
Line-2 -> Space seperated word/s

Output Format:
--------------
Print an integer as your result


Sample Input-1:
---------------
Goood
Good

Sample Output-1:
----------------
1


Sample Input-2:
---------------
heeelllooo
hello hi helo

Sample Output-2:
----------------
2


'''

def is_emphatic(emp: str, word: str) -> bool:
    # print(emp, word)
    i,j=0,0
    while i<len(emp) and j<len(word):
        if(emp[i]!=word[j]): return False
        # print(emp[i], word[i])
        cnt=1
        cnt1=1
        i+=1
        j+=1
        # print(i,j)
        while(i< len(emp) and emp[i]==emp[i-1]):
            cnt+=1
            i+=1
        while(j<len(word) and word[j]==word[j-1]):
            cnt1+=1
            j+=1
        if cnt<cnt1 or (cnt1<cnt and cnt<3): return False
        
    if i==len(emp) and j==len(word): return True 
    else: return False


emp = input()

words = list(map(str,input().split()))

ans = 0

for word in words:
    if is_emphatic(emp,word): ans+=1
print(ans)
