#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& topo) {
    visited[node] = 1; 

    for (int neighbor : adj[node]) {
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, adj, visited, topo)) return true;
        } else if (visited[neighbor] == 1) {
            return true;
        }
    }

    visited[node] = 2; 
    topo.push_back(node);
    return false;
}




int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v); 
    }

    vector<int> visited(n + 1, 0); 
    vector<int> topo;
    bool has_cycle = false;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, adj_list, visited,topo)) {
                has_cycle = true;
                break;
            }
        }
    }

        if (has_cycle) {
        cout << "Cycle detected, topological sort not possible\n";
    } else {


        reverse(topo.begin(), topo.end());
        for (int node : topo) {
            cout << node << " ";
        }
        cout << "\n";
    }



    return 0;
}
