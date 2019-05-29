#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi p, r;
int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void union_set(int u, int v)
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
    }
}
int main()
{

    int k = 0, c = 0, n = 0, u, v;
    cin >> c;
    string line, ignore;
    char cmd;
    while (c--)
    {
        cin >> n;
        p.assign(n, 0);
        r.assign(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;
        int uns = 0, suc = 0;
        getline(cin, ignore);
        while (getline(cin, line) && line != string(""))
        //while (cin >> cmd)
        {
            //char c;
            //cin >> u >> v;
            //cout << "." << line << endl;
            sscanf(line.c_str(), "%c %d %d", &cmd, &u, &v);
            //cout << ";" << cmd << u << v << endl;
            v -= 1, u -= 1;
            if (cmd == 'c')
                union_set(u, v);
            else
            {
                if (isSameSet(u, v))
                    suc++;
                else
                    uns++;
            }
        }
        printf("%d,%d\n", suc, uns);
        if (c)
        {
            cout << endl;
            p.clear();
            r.clear();
        }
    }
    return 0;
}