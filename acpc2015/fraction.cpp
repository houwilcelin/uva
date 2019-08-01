#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y)
{
    return __gcd(x, y);
}
ll lcm(ll x, ll y, ll pgcd = -1)
{
    return (x * y) / gcd(x, y);
}
int main()
{
    //freopen("in", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll a, b, c, d, ab, cd, ac, bd, e, f, g, h, ef, gh;
        cin >> a >> b >> c >> d;
        //printf("abcd -> %lld %lld %lld %lld\n", a, b, c, d);
        ab = gcd(a, b), cd = gcd(c, d);
        a /= ab, b /= ab, c /= cd, d /= cd;
        ac = gcd(a, c), bd = gcd(b, d);
        //printf("gcd -> %lld %lld %lld %lld\n", ab, cd, ac, bd);
        e = ac, f = lcm(b, d, bd), g = lcm(a, c, ac), h = bd;
        ef = gcd(e, f), gh = gcd(g, h);
        e /= ef, f /= ef, g /= gh, h /= gh;
        printf("%lld/%lld %lld/%lld\n", e, f, g, h);
    }
}