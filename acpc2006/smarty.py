def read_int(pattern, pos):
    ints = ""
    while pattern[pos] == ' ':
        pos += 1
    while pattern[pos] != " ":
        ints += pattern[pos]
        pos += 1
    return int(ints), pos


def read_str(pattern, pos):
    st, stop = "", " "
    while pattern[pos] == ' ':
        pos += 1
    if pattern[pos] == '"':
        stop = '"'
        pos += 1
    while pos < len(pattern) and pattern[pos] != stop:
        st += pattern[pos]
        pos += 1
    return st, pos + (1 if stop == ' ' else 2)


def parse(p):
    a, b, c, d = "", "", "", ""
    pos = 0
    # cin>>a
    a, pos = read_int(p, pos)
    # cin>>b
    b, pos = read_int(p, pos)
    # cin>>c
    c, pos = read_str(p, pos)
    # cin>>d
    d, pos = read_str(p, pos)
    # print((a, b, c, d))
    return a, b, c, d


with open('smarty.in') as f:
    line = f.readline().rstrip()
    i = 1
    while line != "0":
        a, b, c, d = parse(line)
        bl, bli = a / b, a // b
        if bl > bli:
            bli += 1
        if bli % 2 != 0:
            print("%d. %s" % (i, c.lower()))
        else:
            print("%d. %s" % (i, d.lower()))
        line = f.readline().rstrip()
        i += 1
