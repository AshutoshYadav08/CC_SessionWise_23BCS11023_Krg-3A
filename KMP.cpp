#include<bits/stdc++.h>
using namespace std;




int main(){

    string pattern = "cba";
    string s = "abcabcbadbbcba";
    int m = pattern.size();
    int n = s.size();

    
    vector<int> lps(m,0);

    // --- 1. Compute LPS (Longest Proper Prefix Suffix) array ---
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // --- 2. KMP Search ---
    i = 0; // index for text s
    int j = 0; // index for pattern
    while (i < n) {
        if (pattern[j] == s[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1]; // Continue searching for next match
        } else if (i < n && pattern[j] != s[i]) {
            // Mismatch after j matches.
            // Instead of matching lps[j-1] characters, we just move j.
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}