#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    int c;
    cin >> c;
    bitset<26> pts;
    getline(cin, line);
    while (c--)
    {
        char a, b;
        int edges = 0;
        pts.reset();
        while (getline(cin, line) && line.find("*") == string::npos)
        {
            sscanf(line.c_str(), "(%c,%c)", &a, &b);
            pts.set(a - 'A');
            pts.set(b - 'A');
            //cout<<a<<b<<endl;
            edges++;
        }
        getline(cin, line);
        string interm;
        stringstream l1(line);
        int v = 0;
        //cout << line << endl;
        while (getline(l1, interm, ','))
        {
            v++;
            //cout<<interm<<endl;
        }
        int tr = v - edges, ac = v - pts.count();
        printf("There are %d tree(s) and %d acorn(s).\n", tr - ac, ac);
    }
    return 0;
}