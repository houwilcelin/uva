#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int k;
    while (cin >> k)
    {
        vector<pii> solutions;
        for (int y = k + 1; y <= 2 * k; ++y)
        {
            if ((k * y) % (y - k) == 0)
                solutions.push_back(pii((k * y) / (y - k), y));
        }
        cout << solutions.size() << endl;
        for (int i = 0; i < (int)solutions.size(); ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, solutions[i].first, solutions[i].second);
    }
    return 0;
}