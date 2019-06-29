#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 20001;
int heads[N], knight[N];
int main()
{
    //freopen("in", "r", stdin);
    while (cin >> n >> m && (n + m))
    {
        for (int i = 0; i < n; i++)
            cin >> heads[i];
        for (int i = 0; i < m; i++)
            cin >> knight[i];
        sort(knight, knight + m);
        sort(heads, heads + n);
        int pay = 0, h = 0, k = 0;
        while (h < n && k < m)
        {
            while (heads[h] > knight[k] && k < m)
                k++;
            if (k == m)
                break;
            pay += knight[k];
            //printf("pay %d\n",pay);
            h++, k++;
        }
        if (h == n)
            printf("%d\n", pay);
        else
            printf("Loowater is doomed!\n");
    }
}