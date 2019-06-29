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
const int MAX_V = 50001, MAX_N = 100;
int V = MAX_V + MAX_N + 2, t = V - 1, s = 0;
void init()
{
    adjList.assign(V, vi());
    edges.clear();
}
void add_edge(int u, int v, ll c)
{
    edges.push_back(Edge(u, v, c));
    adjList[u].push_back(edges.size() - 1);
    edges.push_back(Edge(v, u, 0));
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
/*void print(vi arr)
{
    cout << arr.size();
    int l = arr[0], r = arr[0] + 1;
    for(int i=1;i<arr.size())
}*/
int main()
{
    //freopen("in", "r", stdin);
    int n, m, v, a, b, tt = 1;
    while (cin >> n && n)
    {
        init();
        ll sum_v = 0;
        cin >> m;
        for (int i = 1; i <= MAX_V; i++)
            add_edge(s, i, m);
        for (int i = 1; i <= n; i++)
        {
            cin >> v >> a >> b;
            sum_v += v;
            add_edge(MAX_V + i, t, v);
            for (int j = a; j < b; j++)
                add_edge(j + 1, MAX_V + i, 1);
        }
        string noyes = (dinic(s, t) == sum_v) ? "Yes" : "No";
        printf("Case %d: %s\n", tt++, noyes.c_str());
        if (noyes == string("Yes"))
        {
            vector<ii> memo[n + 1];
            for (int i = 1; i <= MAX_V; i++)
            {
                //printf("for %d\n", i);
                for (auto idx : adjList[i])
                {
                    Edge edge = edges[idx];
                    if (edge.v >= MAX_V + 1 && edge.v <= MAX_V + n)
                    {

                        //printf("edge %d %d -> %d\n", i, edge.v, edge.f);
                        if (edge.f == 1)
                        {
                            int j = edge.v - MAX_V;
                            if (memo[j].size() == 0)
                                memo[j].push_back(ii(i - 1, i));
                            else
                            {
                                ii &las = memo[j].back();
                                if (i - 1 == las.second)
                                    las.second++;
                                else
                                    memo[j].push_back(ii(i - 1, i));
                            }
                            //printf("%d -> %d\n", i - 1, edge.v);
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                cout << memo[i].size();
                for (int j = 0; j < memo[i].size(); j++)
                    printf(" (%d,%d)", memo[i][j].first, memo[i][j].second);
                cout << endl;
            }
        }
    }
}