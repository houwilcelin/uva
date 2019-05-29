#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef unordered_map<string, int> umap;
umap names;
vi p, r, s;
int N = 100000;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
int union_set(int u, int v)
{
    if (!isSameSet(u, v))
    {
        int x = findSet(u), y = findSet(v);
        if (r[x] > r[y])
        {
            p[y] = x;
            s[x] += s[y];
            return s[x];
        }
        else
        {
            p[x] = y;
            s[y] += s[x];
            if (r[x] == r[y])
                r[y]++;
            return s[y];
        }
    }
    return s[findSet(u)];
}
int int_name(string name, int &ncount)
{
    umap::iterator it = names.find(name);
    if (it == names.end())
    {
        names[name] = ncount++;
        return names[name];
    }
    return it->second;
}
int main()
{
    int cases, ncount, n;
    cin >> cases;
    while (cases--)
    {
        ncount = 0;
        p.assign(N, 0), r.assign(N, 0), s.assign(N, 1);
        for (int i = 0; i < N; i++)
            p[i] = i;
        names.clear();
        cin >> n;
        string f1, f2;
        for (int i = 0; i < n; i++)
        {
            cin >> f1 >> f2;
            int u = int_name(f1, ncount), v = int_name(f2, ncount);
            cout << union_set(u, v)<< endl;
        }
    }
}