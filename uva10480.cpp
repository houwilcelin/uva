#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
struct Edge
{
    int u, v;
    ll f, c;
    Edge(int _u, int _v, ll _c) : u(_u), v(_v), c(_c), f(0) {}
};
ll INF = 1e29;
vector<vi> adjList;
vector<ii> path;
vi dist, last;
vector<Edge> edges;
const int MAX_V = 55;
int V = 55, t = 1, s = 0;
void init()
{
    adjList.assign(V, vi());
    edges.clear();
}
void add_edge(int u, int v, ll c)
{
    edges.push_back(Edge(u, v, c));
    adjList[u].push_back(edges.size() - 1);
    edges.push_back(Edge(v, u, c));
    adjList[v].push_back(edges.size() - 1);
}
bool bfs(int s, int t)
{
    dist.assign(V, -1);
    dist[s] = 0;
    path.assign(V, ii(-1, -1));
    queue<int> fringe({s});
    while (!fringe.empty())
    {
        int u = fringe.front();
        fringe.pop();
        for (auto idx : adjList[u])
        {
            Edge edge = edges[idx];
            if (dist[edge.v] == -1 && (edge.c - edge.f) > 0)
            {
                dist[edge.v] = dist[u] + 1;
                path[edge.v] = ii(u, idx);
                fringe.push(edge.v);
            }
        }
    }
    return dist[t] != -1;
}

ll dfs(int s, int t, ll f = INF)
{
    if (s == t || f == 0)
        return f;
    for (int &i = last[s]; i < adjList[s].size(); i++)
    {
        Edge *edge = &edges[adjList[s][i]];
        Edge *bEdge = &edges[adjList[s][i] ^ 1];
        if (dist[edge->v] == dist[edge->u] + 1 && (edge->c - edge->f) > 0)
        {
            if (ll flow_to_push = dfs(edge->v, t, min(f, edge->c - edge->f)))
            {
                edge->f += flow_to_push;
                bEdge->f -= flow_to_push;
                return flow_to_push;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t)
{
    ll mf = 0;
    while (bfs(s, t))
    {
        last.assign(V, 0);
        while (ll f = dfs(s, t))
            mf += f;
    }
    return mf;
}
int main()
{
    //freopen("in", "r", stdin);
    int n, m, u, v;
    ll w;
    while (cin >> n >> m && (n))
    {
        init();
        while (m--)
        {
            cin >> u >> v >> w;
            add_edge(u - 1, v - 1, w);
        }
        dinic(s, t);
        bitset<55> scut;
        queue<int> fringe({s});
        while (!fringe.empty())
        {
            int u = fringe.front();
            fringe.pop();
            scut.set(u);
            for (auto idx : adjList[u])
            {
                Edge edge = edges[idx];
                if (!scut[edge.v] && (edge.c - edge.f) > 0)
                    fringe.push(edge.v);
            }
        }
        for (int node = 0; node < MAX_V; node++)
        {
            if (scut[node])
                for (auto idx : adjList[node])
                {
                    Edge edge = edges[idx];
                    if (!scut.test(edge.v) && (edge.c <= edge.f))
                    {
                        printf("%d %d\n", node + 1, edge.v + 1);
                    }
                }
        }
        cout << endl;
    }
}