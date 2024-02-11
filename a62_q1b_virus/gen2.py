chars = ['a','b']

def permu(length, n, s):
    if (n == length):
        print(s)
        return
    for i in range(len(chars)):
        permu(length, n+1, s+chars[i])

def gen(s, k, n):
    if (n == k):
        return s[::-1]
    if (n == 0):
        return [1,0]
    permu(n, 0, '')    
