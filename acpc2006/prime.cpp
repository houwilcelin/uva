#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000002
//#define MAX_N 21
int p[MAX_N], prime[MAX_N];
int cnt(int a, int b)
{
    int c = 0;
    while (a % b == 0)
    {
        a /= b;
        c += 1;
    }
    return c;
}

void init()
{
    memset(p, 0, sizeof p);
    p[1] = 0;
    memset(prime, 0, sizeof prime);
    for (int i = 2; i < MAX_N; i++)
    {
        if (prime[i] == 0)
            for (int j = 2 * i; j < MAX_N; j += i)
            {
                prime[j] += 1;
                p[j] += cnt(j, i);
            }
    }
    for (int i = 2; i < MAX_N; i++)
        if (!prime[i])
            p[i] = -1;
}

int main()
{
    //freopen("prim.in", "r", stdin);
    init();
    int l, u, tt = 1;
    while (cin >> l >> u && l != -1)
    {
        int ms = 0, sum = 0, max_p = -1e9;
        for (int i = l; i <= u; i++)
        {
            sum += p[i] - 1;
            max_p = max(p[i] - 1, max_p);
            ms = max(ms, sum);
            if (sum < 0)
                sum = 0;
        }
        if (max_p < 0)
            ms = max_p;
        printf("%d. %d\n", tt++, ms);
    }
}