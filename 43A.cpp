#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    unordered_map<string,int> mp;

    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        mp[s]++;
    }

    pair<string,int> ans = {"",0};

    for(auto it : mp){
        if(it.second > ans.second){
            ans = {it.first,it.second};
        }
    }
    
    cout<<ans.first<<endl;


}