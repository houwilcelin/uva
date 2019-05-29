#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int indx[N], nbr[N];
int n;
int main()
{
end:
    while (scanf("%d", &n) && n)
    {
        /*memset(indx, -1, sizeof indx);
        memset(nbr, -1, sizeof nbr);*/
        scanf(":");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nbr[i]);
            indx[nbr[i]] = i;
        }
        for (int j = 0; j < n - 1; j++)
            for (int i = 0; i < j; i++)
            {
                int idx = 2 * nbr[j] - nbr[i];
                if (idx >= 0 && idx < n && indx[idx] > j)
                {
                    cout << "no" << endl;
                    //printf("%d %d %d",nbr[i],nbr[j],nbr[indx[idx]]);
                    goto end;
                }
            }
        cout << "yes" << endl;
    }
}