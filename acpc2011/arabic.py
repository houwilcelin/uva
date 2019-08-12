import re
import itertools

pattern = re.compile(r'([#\s]*)([a-z]*)([#\s]*)')


def processline(line: str):
    l, e, r = pattern.match(line).groups()
    if (e == ""): return line
    # print((l, e, r))
    return r.lstrip() + (" " if len(r) > 0 else "") + e + (" " if len(l) > 0 else "") + l.rstrip()


T = int(input())
for i in range(T):
    w = int(input())
    print(processline(input()))
