#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;

int dist[20][20];
int memo[1 << 20][20];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int ans = INF;
    
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int current_cost = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans,current_cost );
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    n = 4; 

    int graph[4][4] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };
    memcpy(dist, graph, sizeof(graph));


    memset(memo, -1, sizeof(memo));

    cout << "Minimum cost: " << tsp(1, 0) << "\n";

    return 0;
}
