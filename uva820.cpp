#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
const ll INF = 1e18;
struct Edge
{
    int u, v;
    ll f, c;
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c), f(0) {}
};
vi dist;
vector<ii> path;
vector<vi> adjList;
vector<Edge> edges;
int V, s, t, n;
void add_edge(int u, int v, int c)
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
        for (int idx : adjList[u])
        {
            Edge edge = edges[idx];
            if (dist[edge.v] == -1 && (edge.c - edge.f) > 0)
            {
                dist[edge.v] = dist[edge.u] + 1;
                path[edge.v] = ii(u, idx);
                fringe.push(edge.v);
            }
        }
    }
    return dist[t] != -1;
}
ll send_one_flow(int s, int t, ll f = INF)
{
    if (s == t)
        return f;
    int u = path[t].first, idx = path[t].second;
    Edge *edge = &edges[idx];
    ll flow_to_push = send_one_flow(s, u, min(f, edge->c - edge->f));
    edge->f += flow_to_push;
    Edge *bEdge = &edges[idx ^ 1];
    bEdge->f -= flow_to_push;
    return flow_to_push;
}
ll max_flow(int s, int t)
{
    ll mf = 0;
    while (bfs(s, t))
    {
        ll f = send_one_flow(s, t);
        if (f == 0)
            break;
        mf += f;
    }
    return mf;
}
void init()
{
    V = n;
    edges.clear();
    adjList.assign(V, vi());
}
int main()
{
    //freopen("in", "r", stdin);
    int tt = 1;
    while (cin >> n && n)
    {
        init();
        int c, u, v, w;
        cin >> s >> t >> c;
        while (c--)
        {
            cin >> u >> v >> w;
            add_edge(u - 1, v - 1, w);
            //printf("add_edge(%d,%d,%d)\n", u - 1, v - 1, w);
        }
        //ll mf = ;
        //cout << mf << "kk";
        printf("Network %d\nThe bandwidth is %lld.\n\n", tt++, max_flow(s - 1, t - 1));
    }
}