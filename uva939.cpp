#include <bits/stdc++.h>

using namespace std;
struct person
{
    string gene;
    vector<string> parents;
    person(string gene = string("inc_"))
    {
        this->gene = gene;
    }
};

map<string, person> persons;
string ne = string("non-existent"), r = string("recessive"), d = string("dominant");
string genefor(string name)
{
    person p = persons[name];
    if (p.gene != string("inc_"))
        return p.gene;
    string g1 = genefor(p.parents.front()), g2 = genefor(p.parents.back());
    string dec = ne; //g1 + string("-") + g2 + string("|");
    if ((g1 != ne && g2 != ne) || g2 == d || g1 == d)
        dec = r;
    if ((g1 == d && g2 != ne) || (g2 == d && g1 != ne))
        dec = d;
    p.gene = dec;
    persons[name] = p;
    return dec;
}
int main()
{
    int n;
    string a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (b == ne || b == r || b == d)
        {
            person p;
            p.gene = b;
            persons[a] = p;
            //cout<<".."<<p.gene<<endl;;
        }
        else
        {
            map<string, person>::iterator it = persons.find(b);
            person p;
            if (it != persons.end())
                p = it->second;
            p.parents.push_back(a);
            persons[b] = p;
            //cout << '.' << p.parents.back() << endl;
        }
    }
    map<string, person>::iterator it = persons.begin();
    while (it != persons.end())
    {
        string a = it->first;
        printf("%s %s\n", a.c_str(), genefor(a).c_str());
        it++;
    }
    //cout << genefor(string("Marta")) << endl;
    return 0;
}