#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;
int main()
{
    int n, k;
    string s;
    vii v(26);
    bitset<26> wakeup;
end:
    while (cin >> n && cin >> k)
    {
        fill(v.begin(), v.end(), vector<int>());
        wakeup.reset();
        getline(cin, s); //ignore k line
        getline(cin, s);
        for (char c : s)
        {
            wakeup.set(c - 'A');
        }
        for (int i = 0; i < k; i++)
        {
            getline(cin, s);
            char a = s[0] - 'A', b = s[1] - 'A';
            v[a].push_back(b), v[b].push_back(a);
        }
        int years = 0;
        while (wakeup.count() < n)
        {
            vector<int> w;
            for (int i = 0; i < 26; i++)
            {
                if (!wakeup[i])
                {
                    int wakeneigh = 0;
                    for (int neigh : v[i])
                    {
                        if (wakeup[neigh])
                            wakeneigh++;
                        if (wakeneigh == 3)
                            break;
                    }
                    if (wakeneigh >= 3)
                    {
                        w.push_back(i);
                        //wakeup.set(i);
                       // printf("y %d: wake %c\n", years, i + 'A');
                    }
                }
            }
            if (w.empty())
            {
                cout << "THIS BRAIN NEVER WAKES UP\n";
                goto end;
            }
            for (int i : w)
                wakeup.set(i);
            years++;
        }
        cout << "WAKE UP IN, " << years << ", YEARS\n";
    }
    return 0;
}