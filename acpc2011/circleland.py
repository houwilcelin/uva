import itertools

f = open('circleland.in')


def input_():
    return f.readline().strip()
    # return input()


T = int(input_())
for i in range(T):
    line = list(map(int, input_().split()[1:]))
    # print(line)
    acc = list(itertools.accumulate(line))
    ans = 1e10
    for j in range(0, len(acc)):
        l, r = 0, 0#left and right
        if j > 0:
            l = acc[j - 1]
        if j < len(acc) - 1:
            r = acc[-1] - acc[j]
        ans = min(ans, 2 * l + r, 2 * r + l)
    print(ans)
