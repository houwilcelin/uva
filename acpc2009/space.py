import math
keys = set()
def decompose(n):
    fac = dict()
    while n>1:
        found = False
        for i in range(2,int(math.sqrt(n))+1):
            if n % i == 0:
                fac[i] = fac.get(i,0)+1
                keys.add(i)
                n = n//i
                found = True
                break
        if not found:
            fac[n] = fac.get(n,0)+1
            keys.add(n)
            n = 1
    return fac
with open('space.in') as f:
    a,b = map(int,f.readline().split())
    t =1
    while (a,b) != (0,0):
        keys = set()
        acom = decompose(a)
        bcom = decompose(b)
        s = 0
        for k in keys:
            s+= abs(acom.get(k,0)-bcom.get(k,0))
        print("%d. %d:%d"%(t,len(keys),s))
        t+=1
        a,b = map(int,f.readline().split())