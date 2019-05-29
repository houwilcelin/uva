#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi p, r;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
int union_set(int u, int v)
{
    if (!isSameSet(u, v))
    {
        int x = findSet(u), y = findSet(v);
        if (r[x] > r[y])
            p[y] = x;
        else
        {
            p[x] = y;
            if (r[x] == r[y])
                r[y]++;
        }
        return 1;
    }
    return 0;
}
int main()
{

    int k = 1, c, n, m, u, v;
    while (cin >> n >> m && (m + n))
    {
        p.assign(n, 0);
        r.assign(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;
        //cout << "yes" << m << n << endl;
        int disjoint = n;
        while (m--)
        {
            cin >> u >> v;
            u -= 1, v -= 1;
            disjoint -= union_set(u, v);
            //cout <<"eh" << u <<"-"<< v << endl;
        }
        printf("Case %d: %d\n", k++, disjoint);
    }

    return 0;
}
