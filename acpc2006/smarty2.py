import re

p1 = re.compile(r'\s*(\d+)\s+(\d+)\s+(\w+)\s+(\w+)\s*')
p2 = re.compile(r'\s*(\d+)\s+(\d+)\s+(\w+)\s+"([\s\w]+)"\s*')
p3 = re.compile(r'\s*(\d+)\s+(\d+)\s+"([\s\w]+)"\s+(\w+)\s*')
p4 = re.compile(r'\s*(\d+)\s+(\d+)\s+"([\s\w]+)"\s+"([\s\w]+)"\s*')


def find_pattern(p):
    if p1.match(p) is not None:
        return p1
    if p2.match(p) is not None:
        return p2
    if p3.match(p) is not None:
        return p3
    if p4.match(p) is not None:
        return p4


with open('smarty.in') as f:
    line = f.readline().rstrip()
    i = 1
    while line != "0":
        a, b, c, d = find_pattern(line).match(line).groups()
        a = int(a)
        b = int(b)
        bl, bli = a / b, a // b
        if bl > bli:
            bli += 1
        if bli % 2 != 0:
            print("%d. %s" % (i, c.lower()))
        else:
            print("%d. %s" % (i, d.lower()))
        line = f.readline().rstrip()
        i += 1

