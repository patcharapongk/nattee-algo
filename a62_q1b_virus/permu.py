chars = ['a','b']

def permu(length, n, s):
    if (n == length):
        print(s)
        return
    for i in range(len(chars)):
        permu(length, n+1, s+chars[i])

permu(2, 0, '')
