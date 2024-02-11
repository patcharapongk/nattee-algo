def gen(ans,arr,k,n):
    if (n == k):
        arr.append(ans) 
        return
    for item in arr:
        gen(ans+item, arr, k, n+1)

print(gen("",['a'],1,0))
        
