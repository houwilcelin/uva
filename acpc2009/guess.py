with open('guess.in') as f:
    no = int(f.readline())
    t =1
    while no!=0:
        n1=3*no
        if n1%2==0:
            n2=n1/2
            x=1
            st="even"
        else:
            n2=(n1+1)/2
            x=2
            st="odd"
        n4=(3*n2)//9
        if x==1:
            print("%d. %s %d"%(t,st,n4))
        else:
            print("%d. %s %d"%(t,st,n4))
        t+=1
        no = int(f.readline())
    
    