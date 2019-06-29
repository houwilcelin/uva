#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50004;
int N, TC, u, v;
int adj[MAX_N], sum[MAX_N];
bitset<50004> visited;
int dfs(int u)
{
    int v = adj[u], r = 1;
    visited.set(u);
    if (!visited[v])
        r = dfs(v) + 1;
    visited.reset(u);
    return sum[u] = r;
}
int main()
{
    //freopen("in", "r", stdin);
    int tt = 1;
    cin >> TC;
    while (TC--)
    {
        //visited.reset();
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> u >> v;
            adj[u] = v;
            sum[i + 1] = -1;
        }
        int max_c = -1, max_i = -1;
        for (int i = 1; i <= N; i++)
        {
            if (sum[i] == -1)
                dfs(i);
            if (sum[i] > max_c)
                max_c = sum[i], max_i = i;
        }
        printf("Case %d: %d\n", tt++, max_i);
    }
    return 0;
}