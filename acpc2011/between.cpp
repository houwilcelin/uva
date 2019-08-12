#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001
int m[MAX_N], n, TC, n2, val;
main()
{
    //freopen("b.in", "r", stdin);
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        cin >> n2;
        int ans = 1e9;
        for (int i = 0; i < n2; i++)
        {
            cin >> val;
            for (int j = 0; j < n; j++)
                ans = min(ans, abs(val - m[j]));
        }
        printf("%d\n", ans);
    }
}