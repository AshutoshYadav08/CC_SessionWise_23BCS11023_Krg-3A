#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size,rank;


    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        rank.resize(n,1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
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
        } else {

            parent[pv] = pu;
            size[pu] += size[pv];
        }

    }
    
    
    void unionByRank(int u,int v){
        
        int pv = parent[v];
        int pu = parent[u];
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        
    }
    
};



int main() {
    DSU dsu(7);

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);

    dsu.unionBySize(4,5);

    if(dsu.findParent(1) == dsu.findParent(3))
        cout << "1 and 3 are in same set\n";
    else
        cout << "1 and 3 are in different set\n";

    if(dsu.findParent(1) == dsu.findParent(5))
        cout << "1 and 5 are in same set\n";
    else
        cout << "1 and 5 are in different set\n";

    
    dsu.unionBySize(3, 5);

    if(dsu.findParent(1) == dsu.findParent(5))
        cout << "After union, 1 and 5 are in same set\n";

    return 0;
}