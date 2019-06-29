#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int M, C, TC, k;
const int inf = -1e9, MAX_M = 201, MAX_G = 21;
vector<vi> garments;
int memo[MAX_G][MAX_M];
int shop(int money, int g)
{
    if (money < 0)
        return inf;
    if (g == C)
    {
        //printf("%d->%d\n", g, money);
        return M - money;
    }
    if (memo[g][money] != -1)
        return memo[g][money];
    int ans = inf;
    for (int amount : garments[g])
    {
        ans = max(ans, shop(money - amount, g + 1));
    }
    memo[g][money] = ans;
    return ans;
}
int main()
{
    //freopen("in", "r", stdin);
    cin >> TC;
    while (TC--)
    {
        for (int i = 0; i < MAX_G; i++)
            memset(memo[i], -1, sizeof memo[i]);
        cin >> M >> C;
        garments.assign(C, vi());
        for (int i = 0; i < C; i++)
        {
            cin >> k;
            garments[i].assign(k, -1);
            for (int j = 0; j < k; j++)
                cin >> garments[i][j];
        }
        int r = shop(M, 0);
        if (r == inf)
            cout << "no solution" << endl;
        else
            cout << r << endl;
    }
}