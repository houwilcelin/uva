#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> freq;
    vector<string> save;
    int k = 0, c = 0;
    cin >> c;
    string line, ignore;
    getline(cin, ignore);
    getline(cin, ignore);
    while (c--)
    {
        k = 0;
        while (getline(cin, line) && line != string(""))
        {
            unordered_map<string, int>::iterator it = freq.find(line);
            freq[line] = 1 + (it != freq.end() ? it->second : 0);
            k++;
            if (it == freq.end())
                save.push_back(line);
        }
        sort(save.begin(), save.end());
        for (auto s : save)
        {
            int it = freq[s];
            double f = (double)it / k;
            printf("%s %.4f\n", s.c_str(), f * 100);
        }
        if (c)
            printf("\n");
        freq.clear();
        save.clear();
    }
    //cout << "end";
    return 0;
}