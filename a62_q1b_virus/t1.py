import sys
input = sys.stdin.readline

def check_divoc(arr, k):
    if k == 1:
        return arr[0:2] == [0,1]


    left = check_divoc(arr[:len(arr)//2], k-1)
    right = check_divoc(arr[len(arr)//2:], k-1)
    left_rev = check_divoc(arr[:len(arr)//2][::-1], k-1)    
    return (left or left_rev ) and right

n, k  = [int(x) for x in input().split()]
for i in range(n):
    query = [int(x) for x in input().split()]
    result = "yes" if  check_divoc(query, k) == True else "no"
    print(result)

