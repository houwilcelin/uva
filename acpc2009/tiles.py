with open('tiles.in') as f:
    pgcd = lambda a,b : a if b == 0 else pgcd(b,a%b)
    ppcm= lambda a,b : (a*b) // pgcd(a,b)
    a,b = map(int,f.readline().split())
    while (a,b) != (0,0):
        print(ppcm(a,b)**2 // (a*b))
        a,b = map(int,f.readline().split())
