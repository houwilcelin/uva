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
int V = 1 + 26 + 10 + 1, t = V - 1, flow;
void add_edge(int u, int v, int c)
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
void process_line(string line)
{
    int app = line[0] - 'A', x = line[1] - '0', i = 3;
    add_edge(0, app + 1, x);
    while (line[i] != ';')
    {
        add_edge(app + 1, line[i] - '0' + 27, (ll)1);
        //printf("add edge(%c,%d,%lld)\n", 'A' + app, line[i] - '0' + 27, (ll)1);
        i++;
    }
    flow += x;
}
void init()
{
    edges.clear();
    adjList.assign(V, vi());
    for (int i = 27; i <= 36; i++)
        add_edge(i, t, 1);
    flow = 0;
}
void process_test_case()
{
    ll mf = max_flow(0, t);
    if (mf == (ll)flow)
    {
        //printf("yes (%lld %d)\n", mf, flow);
        char c[10] = {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'};
        for (int i = 1; i <= 26; i++)
            for (auto idx : adjList[i])
            {
                Edge edge = edges[idx];
                if (edge.v >= 27 && edge.v <= 36 && edge.f == 1)
                {
                    c[edge.v - 27] = 'A' + i - 1;
                }
            }
        for (int i = 0; i < 10; i++)
            cout << c[i];
        cout << endl;
    }
    else
        cout << '!' << endl; //printf("no (%lld %d)\n",mf,flow);
}
int main()
{
    freopen("in", "r", stdin);
    string line;
    init();
    while (getline(cin, line))
    {
        //cout << line << endl;
        if (line != "")
            process_line(line);
        else
        {
            process_test_case();
            init();
        }
    }
    process_test_case();
}