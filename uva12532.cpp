#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

typedef vector<int> vi;

class FenwickTree
{ // remember that index 0 is not used
private:
    vi ft;
    int n; // recall that vi is: typedef vector<int> vi;
public:
    FenwickTree(int _n) : n(_n) { ft.assign(n + 1, 0); } // n+1 zeroes
    int rsq(int j)
    { // returns RSQ(1, j)
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }
    int rsq(int i, int j) { return rsq(j) - (i == 1 ? 0 : rsq(i - 1)); } // returns RSQ(i, j)
    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, int v)
    {
        for (; i <= n; i += LSOne(i))
            ft[i] += v;
    } // note: n = ft.size()-1
    int select(int k)
    { // O(log^2 n)
        int lo = 1, hi = n;
        for (int i = 0; i < 30; i++)
        {                            // 2^30 > 10^9 > usual Fenwick Tree size
            int mid = (lo + hi) / 2; // Binary Search the Answer
            (rsq(1, mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
};
int norm(int k)
{
    return (k > 0 ? 1 : (k == 0) ? 0 : -1);
}
int x[100005];
int main()
{
    int n, k, v, i, j;
    while (cin >> n >> k)
    {
        FenwickTree ft_0(n);
        FenwickTree ft_Neg(n);
        char c;
        string res = string("");
        for (int l = 1; l <= n; l++)
        {
            cin >> v;
            x[l] = v;
            v = norm(x[l]);
            //cout << "i" << v << endl;
            if (v == 0)
                ft_0.update(l, 1);
            else if (v == -1)
                ft_Neg.update(l, 1);
        }
        //cout << "iii";
        while (k--)
        {
            cin >> c >> i >> j;
            //getline(cin, ignore);
            //cout << c << i << ":" << j << endl;
            if (c == 'C')
            {
                if (norm(x[i]) != norm(j))
                {
                    if (norm(x[i]) == -1)
                        ft_Neg.update(i, -1);
                    else if (norm(x[i]) == 0)
                        ft_0.update(i, -1);
                    if (norm(j) == -1)
                        ft_Neg.update(i, 1);
                    else if (norm(j) == 0)
                        ft_0.update(i, 1);
                }
                x[i] = j;
                //ft.print_ar();
            }
            else
            {
                if (ft_0.rsq(i, j))
                    res += "0";
                else if (ft_Neg.rsq(i, j) % 2 == 0)
                {
                    res += "+";
                }
                else
                {
                    res += "-";
                }
                /*int r = ft.rmq(i - 1, j - 1);
                res += string((r == 0 ? "0" : (r > 0 ? "+" : "-")));*/
            }
        }
        cout << res << endl;
    }
}