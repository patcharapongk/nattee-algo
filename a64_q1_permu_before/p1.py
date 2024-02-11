constraints = dict()
constraints[2] = [1]
limit = 3

def permu(ans, limit, current, used):
    if current == limit:
        print(ans)
        return
    for i in range(limit):
        if not used[i]:
            used[i] = True
            if i in constraints and current in constraints[i]:
                used[constraints[i][0]] = True
            permu(ans+str(i),limit,current+1, used) 
            if i in constraints and current not in constraints[i]:
                used[constraints[i][0]] = False
            used[i] = False
    
     

permu("", limit, 0, [False]*limit)
