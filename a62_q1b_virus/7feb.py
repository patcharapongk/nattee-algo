def check_virus(arr, size):
    if (size == 1):
        return arr[0:2] == [0,1]
    left_arr = arr[:len(arr)//2]
    right_arr = arr[len(arr)//2:]
    left_rev = left_arr[::-1]
    halfsize = size-1
    return (check_virus(left_arr, halfsize) or check_virus(left_rev, halfsize)) and check_virus(right_arr, halfsize)

n, k  = [int(x) for x in input().split()]
for i in range(n):
    query = [int(x) for x in input().split()]
    result = "yes" if  check_virus(query, k) == True else "no"
    print(result)
