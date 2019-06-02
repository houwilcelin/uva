#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N = 10000;
int n, M, a, b, f, c = 0, v;
int main()
{
    //ifstream cin("in");
    while (cin >> n)
    {

        vi price(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            price[i] = v;
        }
        sort(price.begin(), price.end());
        cin >> M;
        f = 0;
        for (int k = 0; k < n; k++)
        {
            int i = price[k];
            if ((M - i >= 0) && binary_search(price.begin(), price.end(), M - i))
            {
                if (!f || (abs(M - 2 * i) < abs(b - a)))
                {
                    a = i;
                    b = M - i;
                }
                f++;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", min(a, b), max(a, b));
        c++;
    }
}