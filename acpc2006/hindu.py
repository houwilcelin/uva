def digit_sum(nbr):
    return sum(map(int,list(nbr)))
f = open("hindu.in")
i = 1
while True:
    line = f.readline().rstrip()
    if line == ".":
        exit(0)
    else:
        a,b,c,op="","","",""
        _type = 0
        for char in line[:-1]:
            if char in ["*","+","="]:
                _type+=1
                if char != "=":
                    op =char
            else:
                if _type == 0:
                    a+=char
                elif _type == 1:
                    b+=char
                else :c+=char
    #print(a,b,c)
    a_ = digit_sum(a)
    b_ = digit_sum(b)
    c_ = digit_sum(c)
    a__ = a_
    b__ = b_
    ab = 0
    if op == "*":
        ab = a__*b__
    else : ab = a__+b__
    #print(a__,b__,ab,c_)
    if (ab %9) == (c_ %9):
        print(f"{i}. PASS")
    else : print(f"{i}. NOT!")
    i+=1
    #exit(0)