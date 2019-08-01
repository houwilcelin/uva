#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;
#define N 10001
int TC, n, x, y;
vii adjList;
vi dist;
int bfs(int s)
{
    //printf("start bfs");
    dist.assign(n, -1);
    dist[s] = 0;
    queue<int> fringe({s});
    while (!fringe.empty())
    {
        int u = fringe.front();
        fringe.pop();
        for (int v : adjList[u])
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                fringe.push(v);
            }
    }
    int mn = 0;
    for (int i = 1; i < n; i++)
        if (dist[i] > dist[mn])
            mn = i;
    //printf("finish bfs from %d->(%d,%d)\n", s, mn, dist[mn]);
    return mn;
}
int main()
{
    //freopen("batman.01.inp", "r", stdin);
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        adjList.assign(n + 1, vi());
        for (int i = 1; i < n; i++)
        {
            cin >> x >> y;
            x--, y--;
            //printf("read %d %d\n", x, y);
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        //printf("finish read\n");
        cout << n - 1 - dist[bfs(bfs(0))] << endl;
    }
}