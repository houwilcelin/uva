#include <bits/stdc++.h>
using namespace std;
#define MAX_M 10
#define MAX_N 200
#define MAX_D 20
#define p(n) n + 1
typedef long long ll;
ll memo[p(MAX_N)][p(MAX_D)][p(MAX_M)];
ll numbers[p(MAX_N)];
int n, q, D, M;
ll mod(ll a, ll b)
{
    ll m = a % b;
    if (m < 0)
        m += b;
    return m;
}
ll do_cnt(int id = 0, int cnt = 0, ll sum = 0)
{
    //printf("Call %d , %d , %lld\n", id, cnt, sum);
    if (cnt == M)
        if (sum == 0)
            //printf("find %d\n", id);
            return 1;
        else
            return 0;
    if (id == n)
        return 0;
    ll &s = memo[id][sum][cnt];
    if (s != -1)
        return s;
    return s = do_cnt(id + 1, cnt + 1, mod(sum + numbers[id], D)) +
               do_cnt(id + 1, cnt, sum);
}
int main()
{
    //freopen("in", "r", stdin);
    int set = 1, query;
    while (cin >> n >> q && (n + q))
    {
        query = 1;
        printf("SET %d:\n", set++);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        for (int i = 0; i < q; i++)
            cin >> D >> M,
                memset(memo, -1, sizeof memo), printf("QUERY %d: %lld\n", query++, do_cnt());
    }
}