#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
bool visited[N];

void dfs(int node){
    visited[node] = true;

    for(int neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> components;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            components.push_back(i);
            dfs(i);
        }
    }

    cout << components.size() - 1 << "\n";

    for(int i = 1; i < components.size(); i++){
        cout << components[i-1] << " " << components[i] << "\n";
    }
}