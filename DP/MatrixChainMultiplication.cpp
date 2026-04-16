#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& p) {
    int n = p.size();
    
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};
    
    cout << "Minimum number of multiplications is: " 
         << matrixChainOrder(dimensions) << "\n";
         
    return 0;
}
