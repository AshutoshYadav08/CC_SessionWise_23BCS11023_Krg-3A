#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> dict;  // store dictionary words
    string s;

    for(int i = 0; i < n; i++) {
        cin >> s;
        dict.insert(s);
    }

    while(m--) {
        cin >> s;
        bool found = false;

        for(int i = 0; i < s.length(); i++) {
            char original = s[i];

            for(char ch = 'a'; ch <= 'c'; ch++) {
                if(ch == original) continue; 

                s[i] = ch; // modify

                if(dict.count(s)) {
                    found = true;
                    break;
                }
            }

            s[i] = original;

            if(found) break;
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}