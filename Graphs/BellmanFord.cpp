#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source = 1; 
    vector<long long> dist(n + 1, INF);
    dist[source] = 0;


    for (int i = 1; i <= n - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    bool hasNegativeCycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative cycle detected" << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) cout << "INF ";
            else cout << dist[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}