/*************************************************************************
    > File Name: l.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 26 Jul 2014 12:58:48 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n,v[10005],pos;

void Work(int p,int cnt,int d){
    if(cnt == 1){
        v[pos++] = p;
        return;
    }
    int n1 = ceil(1.0 * cnt / 2);
    int n2 = cnt / 2;
    Work(p,n1,2 * d);
    Work(p + d,n2,2 * d);
}

int main(){
    while(scanf("%d",&n) == 1 && n){
        pos = 0;
        Work(0,n,1);
        printf("%d:",n);
        for(int i = 0; i < n; ++i)
            printf(" %d",v[i]);
        printf("\n");
    }
    return 0;
}