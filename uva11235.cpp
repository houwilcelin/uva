#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
class SegmentTree
{
private:
    vi st, arr;
    int n;
    int left(int p) { return 2 * p; }
    int right(int p) { return left(p) + 1; }
    void build(int p, int L, int R)
    {
        //printf("build start for [%d:%d]\n", L, R);
        if (L == R)
        {
            st[p] = L;
            //cout << "_" << L << ":" << p << endl;
        }
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (arr[p1] >= arr[p2]) ? p1 : p2;
            //printf("build for [%d:%d]->%d\n", L, R, arr[st[p]]);
        }
    }
    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R or j < L)
            return -1;
        if (L >= i && R <= j)
            return st[p];
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        return (arr[p1] >= arr[p2]) ? p1 : p2;
    }
    void update(int p, int L, int R, int i, int v)
    {
        if (i < L || i > R)
            return;
        if (i == L && i == R)
        {
            arr[i] = v;
            return;
        }
        update(left(p), L, (L + R) / 2, i, v);
        update(right(p), (L + R) / 2 + 1, R, i, v);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (arr[p1] >= arr[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_arr)
    {
        arr = _arr, n = (int)_arr.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    int update(int i, int value) { update(1, 0, n - 1, i, value); }
    void print()
    {
        cout << "[ ";
        for (int i = 0; i < st.size() - 1; i++)
        {
            cout << arr[st[i]] << ", ";
        }
        cout << arr[st[st.size() - 1]] << " ]" << endl;
    }
};
void print(vi st)
{
    cout << "[ ";
    for (int i = 0; i < st.size() - 1; i++)
    {
        cout << st[i] << ", ";
    }
    cout << st[st.size() - 1] << " ]" << endl;
}
unordered_map<int, pii> indexes;
unordered_map<int, int> arr_index;
void print_map()
{
    cout << "[ ";
    for (auto &it : indexes)
    {
        pii p = it.second;
        printf("{%d:(%d,%d)} ", it.first, p.first, p.second);
    }
    cout << "]" << endl;
}
void print_map_a()
{
    cout << "[ ";
    for (auto &it : arr_index)
    {
        printf("(%d:%d) ", it.first, it.second);
    }
    cout << "]" << endl;
}
int main()
{
    int n, q, i, j;
    while (cin >> n && n)
    {
        indexes.clear();
        arr_index.clear();
        cin >> q;
        vi arr;
        int t[n];
        int s = 1, k, old_k, first = 0;
        cin >> k;
        old_k = k;
        t[0] = k;
        for (int l = 1; l < n; l++)
        {
            cin >> k;
            t[l] = k;
            if (k > old_k)
            {
                indexes[old_k] = pii(first, l - 1);
                arr_index[old_k] = arr.size();
                first = l;
                arr.push_back(s);
                s = 1;
            }
            else
            {
                s++;
            }
            old_k = k;
        }
        indexes[old_k] = pii(first, n - 1);
        arr_index[old_k] = arr.size();
        arr.push_back(s);
        /* print(arr);
        print_map();
        print_map_a();*/
        SegmentTree st(arr);
        for (int l = 0; l < q; l++)
        {
            cin >> i >> j;
            i -= 1, j -= 1;
            if (i == j)
                cout << 1 << endl;
            else if (t[i] == t[j])
            {
                cout << j - i + 1 << endl;
                //cout<<"tii";
            }
            else
            {
                pii i_p = indexes[t[i]], j_p = indexes[t[j]];
                int n_i = arr_index[t[i]], n_j = arr_index[t[j]];
                int l_ij = max(i_p.second - i + 1, j - j_p.first + 1);
                if (n_i + 1 == n_j)
                {
                    cout << l_ij << endl;
                    // cout<<"lii";
                }
                else
                {
                    cout << max(l_ij, arr[st.rmq(n_i + 1, n_j - 1)]) << endl;
                    //cout<<"max";
                }
            }
        }
    }
}