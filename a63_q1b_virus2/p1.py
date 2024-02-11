def count_ones(string):
    count = 0
    for char in string:
        if char == '1':
            count += 1
    return count

def check_virus(virus, n):
    if n == 1:
        return True
    left_virus = virus[:len(virus)//2]
    right_virus = virus[len(virus)//2:]
    diff = abs(count_ones(left_virus)-count_ones(right_virus))
    return diff <= 1 and check_virus(left_virus, n-1) and check_virus(right_virus, n-1)


n, k = [int(x) for x in input().split()]
for i in range(n):
    virus = [x for x in input().split()]
    if check_virus(virus, k):
        print('yes')
    else:
        print('no')
