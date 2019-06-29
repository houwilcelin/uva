#include <bits/stdc++.h>
#define MAX_N 1120
#define MAX_K 14
using namespace std;
typedef vector<int> vi;
bitset<1121> bs;
int N = 0;
vi prime;
vi sum;
int lsum = 0;
void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= MAX_N; i++)
        if (bs[i])
        {
            for (int j = i; j <= MAX_N; j += i)
                bs.reset(j);
            prime.push_back(i);
            lsum += i;
            sum.push_back(lsum);
        }
    N = prime.size();
}
int main()
{
    //freopen("in", "r", stdin);
    sieve();
    int s[MAX_N + 1][MAX_K + 1];
    memset(s, 0, sizeof s);
    for (int val : prime)
    {
        for (int i = MAX_N - val; i >= 0; i--)
        {
            //s[i + val] += s[i];
            for (int k = 1; k < MAX_K; k++)
                s[i + val][k + 1] += s[i][k];
        }
        s[val][1] = 1;
    }
    int w,k;
    while (cin >> w >> k && (w + k))
        printf("%d\n", s[w][k]);
}