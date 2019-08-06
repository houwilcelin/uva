#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int main()
{
    //ifstream cin("in");
    int TC, tc = 1, max_ci = 1, S, N;
    int inf = 1 << 29;
    ll cnt[5010];
    cin >> TC;
    while (TC--)
    {
        max_ci = 1;
        cin >> S >> N;
        vi v(N), c(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i] >> c[i];
            max_ci = max(max_ci, c[i]);
        }
        ll ans = 0;
        for (int k = 1; k <= max_ci; k++)
        {
            if (S % k != 0)
                continue;
            //vi cnt(S + 1, 0);
            memset(cnt, 0, sizeof cnt);
            cnt[0] = 1;
            for (int i = 0; i < N; i++)
                if (c[i] >= k)
                {
                    int num = v[i] * k;
                    for (int s = S; s >= num; s-=k)
                        cnt[s] += cnt[s - num];
                }
            ans += cnt[S];
        }
        printf("Case %d: %lld\n", tc++, ans);
    }
}