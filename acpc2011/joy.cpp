//WRONG_ANSWER
#include <bits/stdc++.h>
#define NotN 2000 // Not a Number or inf
#define MAXN 1002
using namespace std;
typedef vector<int> vi;
class SegmenTree
{
private:
    vi st, A;
    int N;
    int left(int p) { return 2 * p; }
    int right(int p) { return left(p) + 1; }
    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = L;
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = A[p1] >= A[p2] ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
            return NotN;
        if (L >= i && R <= j)
            return st[p];
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == NotN)
            return p2;
        if (p2 == NotN)
            return p1;
        return A[p1] >= A[p2] ? p1 : p2;
    }

public:
    SegmenTree() {}
    SegmenTree(const vi &arr)
    {
        A = arr, N = (int)arr.size();
        st.assign(4 * N, NotN);
        build(1, 0, N - 1);
    }
    int rmq(int i, int j)
    {
        if (i == j)
            return i;
        return rmq(1, 0, N - 1, i, j);
    }
    int get(int idx) { return A[idx]; }
    int getMax() { return rmq(0, N - 1); }
    int max_idx(int p1, int p2) { return A[p1] >= A[p2] ? p1 : p2; }
};
int mod(int a, int b)
{
    if (a < 0)
        a += b;
    return a % b;
}
int main()
{
    //freopen("joy.in", "r", stdin);
    int TC, n, m, k;
    int *cylinder[MAXN], *max_idx[MAXN], *max_sum[MAXN];
    SegmenTree cTree = SegmenTree();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            cylinder[i] = new int[MAXN];
            max_sum[i] = new int[MAXN];
            for (int j = 0; j < m; j++)
            {
                cin >> cylinder[i][j];
                max_sum[i][j] = cylinder[i][j];
            }
        }
        /*printf("_%d \n",  cTree[0].get(0));
        printf("-> %d\n", cTree[0].rmq(0, 5));*/
        bool shouldGetMax = k >= ((m + 1) / 2);
        //printf("df\n");
        //n = 1;
        cTree = SegmenTree(vi(max_sum[n - 1], max_sum[n - 1] + m));
        int midx = 0;
        if (n == 1)
            midx = cTree.getMax();
        for (int i = n - 2; i >= 0; i--)
        {
            max_idx[i] = new int[MAXN];
            for (int j = 0; j < m; j++)
            {
                //int rleft = (j - k + 1) % m, rright = (j + k - 1) % m;
                int rleft = mod(j - k + 1, m), rright = mod(j + k - 1, m);
                if (shouldGetMax)
                    max_idx[i][j] = cTree.getMax();
                else if (rleft <= rright)
                    max_idx[i][j] = cTree.rmq(rleft, rright);
                else
                {
                    int p1 = cTree.rmq(rleft, m - 1), p2 = cTree.rmq(0, rright);
                    max_idx[i][j] = cTree.max_idx(p1, p2);
                }
                //printf("(%d,%d)-> ")
                max_sum[i][j] += max_sum[i + 1][max_idx[i][j]];
                if (i == 0 && max_sum[i][j] > max_sum[i][midx])
                    midx = j;
            }
            cTree = SegmenTree(vi(max_sum[i], max_sum[i] + m));
        }
        max_idx[n - 1] = new int[MAXN];
        memset(max_idx[n - 1], -1, MAXN);
        /* for (int i = 0; i < n; i++)
        {
            printf("%d -> ", i);
            for (int j = 0; j < m; j++)
            {
                printf("(%d:%d:%d) ", cylinder[i][j], max_sum[i][j], max_idx[i][j]);
            }
            cout << endl;
        } */
        printf("%d ", max_sum[0][midx]);
        int idx = midx;
        for (int i = 0; i < n - 1; i++)
            printf("%d ", idx + 1), idx = max_idx[i][idx];
        printf("%d\n", idx + 1);
        //printf("%d %d", cTree[6].rmq(11, 11),cTree[6].rmq(0,));
    }
    return 0;
}