def output(line):
    op,extra = 0,0
    for char in line:
        #print("char",char)
        if char == "{":
            op+=1
        else:
            if op>0: 
                op-=1
            else:
                extra+=1
                op+=1
    op = abs(op)
    #return (op+extra)//2
    #print("op",op,extra)
    if op == 0:
        return extra
    elif op %2 ==0:
        return op//2 + extra
with open('braces.in') as f:
    line = f.readline().rstrip()
    k=1
    while(line[0]!="-"):
        print("%d. %d"%(k,output(line)))
        k+=1
        line = f.readline().rstrip()