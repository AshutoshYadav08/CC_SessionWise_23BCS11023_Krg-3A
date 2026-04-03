#include <bits/stdc++.h>
using namespace std;

int lcsMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcsMemo(s1, s2, i-1, j-1, dp);
    else
        return dp[i][j] = max(lcsMemo(s1, s2, i-1, j, dp),
                             lcsMemo(s1, s2, i, j-1, dp));
}

int main(){
    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << lcsMemo(s1, s2, n-1, m-1, dp);
}