#include <bits/stdc++.h>
using namespace std;
#define PI 3.141
struct pt
{
    double x, y;
    pt(double _x = -1, double _y = -1) : x(_x), y(_y) {}
};
struct cercle
{
    pt o;
    double r;
    cercle(pt _o, double _r = -1) : o(_o), r(_r) {}
};
double dist(pt a, pt b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool in_cercle(cercle c, pt p, double r)
{
    return dist(c.o, p) <= r;
}
int n;
pt pts[1000];
int calcul(double r1, double r2, cercle c1, cercle c2)
{
    int nbr = 0;
    for (int i = 0; i < n; i++)
    {
        if (in_cercle(c1, pts[i], r1) || in_cercle(c2, pts[i], r2))
            nbr++;
    }
    return n - nbr;
}

int main()
{
    double x1, x2, y1, y2, A;
    int tt = 1;
    //freopen("strike.in", "r", stdin);
    while (cin >> n && n)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> A;
        cercle c1(pt(x1, y1)), c2(pt(x2, y2));
        for (int i = 0; i < n; i++)
        {
            cin >> x1 >> y1;
            pts[i] = pt(x1, y1);
        }
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            double r1 = dist(pts[i], c1.o), r2 = dist(pts[i], c2.o);
            double R1 = (A / PI) - r1 * r1, R2 = (A / PI) - r2 * r2;
            if (R1 >= 0)
            {
                int rep = calcul(r1, sqrt(R1), c1, c2);
                ans = min(ans, rep);
                //printf("(%f , %f)%d -> %d\n",r1,R1,i,rep);
            }
            if (R2 >= 0)
            {
                ans = min(ans, calcul(sqrt(R2), r2, c1, c2));
            }
        }
        printf("%d. %d\n", tt++, ans);
    }
}