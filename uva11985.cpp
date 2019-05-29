#include <bits/stdc++.h>
using namespace std;
main()
{
    int sc, sq, spq, n, cmd, v;
    while (cin >> n)
    {
        vector<int> stack;
        queue<int> que;
        priority_queue<int> pque;
        int cmdcount = 0;
        sc = 0;
        sq = 0;
        spq = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cmd >> v;
            if (cmd == 1)
            {
                stack.push_back(v);
                que.push(v);
                pque.push(v);
            }
            else
            {
                sc += (!stack.empty() && stack.back() == v) ? 1 : 0;
                sq += (!que.empty() && que.front() == v) ? 1 : 0;
                spq += (!pque.empty() && pque.top() == v) ? 1 : 0;
                if (!stack.empty())
                    stack.pop_back();
                if (!que.empty())
                    que.pop();
                if (!pque.empty())
                    pque.pop();
                cmdcount++;
            }
        }
        vector<string> pos;
        if (sc == cmdcount)
            pos.push_back(string("stack"));
        if (sq == cmdcount)
            pos.push_back(string("queue"));
        if (spq == cmdcount)
            pos.push_back(string("priority queue"));
        int siz = pos.size();
        //cout << (siz == 1 ? pos.back() : (siz == 3 ? "impossible" : "not sure")) << endl;
        //printf("%d %d %d (%d)", sc, sq, spq, cmdcount);
        if (pos.size() == 1)
            cout << pos.back() << endl;
        else if (pos.size() == 0)
            cout << "impossible\n";
        else
            cout << "not sure\n";
    }
}