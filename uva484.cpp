#include <bits/stdc++.h>

using namespace std;
int get(map<int,int>f,int key) {
    map<int,int>::iterator it=f.find(key);
    if(it!=f.end())
        return it->second;
    else
        return 0;
}
int main() {
    map<int,int>freq;
    int n;
    queue<int>save;
    while(cin>>n) {
        int fn = get(freq,n);
        freq[n] = fn+1;
        if(!fn)
            save.push(n);
    }
    map<int,int>::iterator it=freq.begin();
    while(!save.empty()) {
        int a=save.front(),b=freq[a];
        printf("%d %d\n",a,b);
        save.pop();
    }
    return 0;
}
