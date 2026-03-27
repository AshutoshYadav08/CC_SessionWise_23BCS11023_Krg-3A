#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
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
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];

            
        }
    }
};

int main() {
    int V = 5;
    
    // {weight, u, v}
    vector<vector<int>> edges = {
        {1, 0, 1},
        {3, 1, 2},
        {4, 0, 2},
        {2, 1, 3},
        {5, 3, 4}
    };

    
    sort(edges.begin(), edges.end());

    DSU dsu(V);

    int mstWeight = 0;

    for(auto &edge : edges) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(dsu.findParent(u) != dsu.findParent(v)){
            dsu.unionBySize(u,v);
            mstWeight += wt;
        }
    }

    cout<<"mST weight "<< mstWeight<< endl;

    return 0;
}