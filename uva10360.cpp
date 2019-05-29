#include <bits/stdc++.h>
using namespace std;
#define N 1024
typedef pair<int, int> pii;
int main()
{
    int TC, n, x, y, size, d, v;
    int *kill[N];
    cin >> TC;
    while (TC--)
    {
        for (int i = 0; i < N; i++)
        {
            kill[i] = new int[N];
            for (int j = 0; j < N; j++)
            {
                kill[i][j] = 0;
            }
        }
        pii sol(N + 1, N + 1);
        int msize = -1;
        cin >> d >> n;
        while (n--)
        {
            cin >> x >> y >> size;
            for (int i = y - d; i < y + d + 1; i++)
                if (i > -1 && i < N)
                    for (int j = x - d; j < x + d + 1; j++)
                        if (j > -1 && j < N)
                        {
                            //printf("add to %d %d\n", j, i);
                            kill[i][j] += size;
                            if (kill[i][j] > msize)
                            {
                                sol = pii(j, i), msize = kill[i][j];
                            }
                            else if (kill[i][j] == msize)
                            {
                                sol = min(sol, pii(j, i));
                            }
                        }
        }
        printf("%d %d %d\n", sol.first, sol.second, msize);
    }
    return 0;
}