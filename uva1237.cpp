#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    //ifstream cin("in");
    int TC, d, q, l, r, p;
    string name;
    cin >> TC;
    unordered_map<string, pii> maps;
    while (TC--)
    {
        maps.clear();
        cin >> d;
        for (int i = 0; i < d; i++)
        {
            cin >> name >> l >> r;
            maps[name] = pii(l, r);
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> p;
            int c = 0;
            for (auto it : maps)
            {
                pii iit = it.second;
                if (iit.first <= p && iit.second >= p)
                {
                    name = it.first;
                    c++;
                    if(c>1) break;
                }
            }
            if (c == 1)
                cout << name << endl;
            else
                cout << "UNDETERMINED" << endl;
        }
        if (TC)
            cout << endl;
    }
}