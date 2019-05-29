#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
struct Doll
{
    int h, w;
    int operator<(Doll d)
    {
        if (d.w == w)
            return h < d.h;
        return w > d.w;
    }
};
int main()
{
    //int A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
    //cout << (Doll(1, 2) < Doll(1, 5) ? "true" : "false");
    //return 0;
    ifstream cin("in");
    int n, TC;
    vector<Doll> A;
    cin >> TC;
    while (TC--)
    {
        while (!A.empty())
            A.pop_back();
        cin >> n;
        int lis = 0, lis_end = 0, h, w;
        int L[N];
        for (int i = 0; i < n; i++)
        {
            cin >> w >> h;
            //printf("cin %d %d\n", w, h);
            A.push_back(Doll{h, w});
        }
        sort(A.begin(), A.end());
        /*for (int i = 0; i < n; ++i)
            printf("A[%d] = (%d,%d)\n", i + 1, A[i].w, A[i].h);*/
        for (int i = 0; i < n; ++i)
        {
            int pos = upper_bound(L, L + lis, A[i].h) - L;
            L[pos] = A[i].h;
            lis = max(lis, pos + 1);
        }
        cout << lis << endl;
    }
    return 0;
}