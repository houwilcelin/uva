#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main()
{
    //ifstream cin("in");
    vector<vi> v(256);
    string S, SS;
    int q;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
        v[S[i]].push_back(i);
    cin >> q;
    while (q--)
    {
        cin >> SS;
        int index = -1, start;
        bool found = true;
        for (int i = 0; i < SS.size(); i++)
        {
            vi vc = v[SS[i]];
            vi::iterator it = upper_bound(vc.begin(), vc.end(), index);
            if (it == vc.end())
            {
                found = false;
                break;
            }
            //index = it - vc.begin();
            index = vc[it - vc.begin()];
            //cout << SS[i] << " " << index << endl;
            if (!i)
                start = index;
        }
        if (!found)
            printf("Not matched\n");
        else
            printf("Matched %d %d\n", start, index);
    }
    return 0;
}