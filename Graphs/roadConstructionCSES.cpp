#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    int components;
    int max_size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        components = n;
        max_size = (n > 0) ? 1 : 0;

        // Initialize for 1-based indexing
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }


    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }


    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            max_size = max(max_size, size[pv]);
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            max_size = max(max_size, size[pu]);
        }

        components--;

    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin>>n>>m;


    DSU dsu(n);

    while(m--){

        int u,v;cin>>u>>v;

        dsu.unionBySize(u,v);
        cout << dsu.components << " " << dsu.max_size << "\n";

    }

    return 0;
}