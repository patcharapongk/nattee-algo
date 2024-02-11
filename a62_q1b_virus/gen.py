def gen(s, k, n):
    if (n == k):
        print(s[::-1])
        return
    if (n == 0):
        gen("1 0 ", k, n+1)
    else:
        a = gen(s+"1 0 ", k, n+1)
        b = gen(s+"0 1 ", k, n+1)

gen("",2,0)
gen("",3,0) 
