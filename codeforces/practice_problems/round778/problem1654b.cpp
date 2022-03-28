#include <bits/stdc++.h>
using namespace std;

//i looked at an official solution and learned a bit how to make better code

int main() {

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        map<char, int> frequency;

        for (char c: s) {
            frequency[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if ( --frequency[s[i]] == 0) {
                cout << s.substr(i) << "\n";
                break;
            }
        }
    }

    return 0;
}