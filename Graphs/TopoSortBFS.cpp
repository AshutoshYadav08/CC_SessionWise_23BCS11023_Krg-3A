#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
   
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }

    if (topo.size() != n) {
        cout << "Cycle \n";
    } else {
        for (int node : topo) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}