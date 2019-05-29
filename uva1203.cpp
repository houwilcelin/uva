#include <bits/stdc++.h>
using namespace std;
class Query
{
public:
    int qnum, cur_time = 0, period;
    Query(int q, int p)
    {
        qnum = q;
        period = p;
        next();
    }
    void next()
    {
        cur_time += period;
    }
};
class Comparator
{
public:
    int operator()(const Query &q1, const Query &q2)
    {
        if (q1.cur_time == q2.cur_time)
            return q1.qnum > q2.qnum;
        return q1.cur_time > q2.cur_time;
    }
};
main()
{
    priority_queue<Query, vector<Query>, Comparator> pq;
    string line;
    while (cin >> line && line != string("#"))
    {
        //char s[9];
        int q, p;
        //sscanf("%8c %d %d", line.c_str(), s, q, p);
        cin >> q >> p;
        //cout << p << q;
        pq.push(Query(q, p));
    }
    int r = 0, max_r;
    cin >> max_r;
    //cout<<"size "<<pq.size()<<endl;
    while (r++ < max_r)
    {
        Query query = pq.top();
        pq.pop();
        cout << query.qnum <<endl;//<< ":" << query.cur_time << endl;
        query.next();
        pq.push(query);
    }
}