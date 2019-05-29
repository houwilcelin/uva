#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int c[20], deg, TC, d, k;
string line, token;
int sol(int k, int d)
{
    /*int p = 0;
    for (int n = 1;; n++)
    {
        int previousp = p;
        p += n * d;
        if (previousp < k && k <= p)
            return n;
    }*/

    ld delta = sqrt(d * d + 8 * d * k);
    return ceil((-d + delta) / (2 * d));
}
int main()
{
    scanf("%d", &TC);
    while (TC--)
    {
        memset(c, 0, sizeof c);
        cin >> deg;
        stringstream l1(line);
        for (int i = 0; i <= deg; i++)
            scanf("%d", &c[i]);
        scanf("%d %d", &d, &k);
        int n = sol(k, d), n_i = 1;
        //cout << "n:" << n << endl;
        ll sum = 0;
        for (int i = 0; i <= deg; i++)
        {
            sum += c[i] * n_i;
            n_i *= n;
            //cout << "sum;" << c[i] * pow(n, i) << endl;
        }
        cout << sum << endl;
    }
    //cout << sol(5, 1);
}