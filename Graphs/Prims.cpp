#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // MST applies to undirected graphs
    }

    // Priority queue to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> inMST(n + 1, false);

    // Start Prim's from node 1
    pq.push({0, 1});
    
    long long mst_cost = 0;
    int nodes_included = 0;

    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the node is already in the MST, skip it
        if (inMST[u]) continue;

        // Include node in MST
        inMST[u] = true;
        mst_cost += w;
        nodes_included++;

        // Traverse all adjacent nodes
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    if (nodes_included == n) cout << mst_cost << "\n";
    else cout << "Graph is disconnected, MST not possible\n";

    return 0;
}