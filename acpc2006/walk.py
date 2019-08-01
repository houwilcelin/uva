with open("walk.in") as f:
    comp = 1
    while True: 
        n = int(f.readline().rstrip())
        if n == 0:
            exit(0)
        result = ((n-1)**2)+n
        print(f"{n} => {result}")
