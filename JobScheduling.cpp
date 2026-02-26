#include <bits/stdc++.h>
using namespace std;

int main()
{

    // int n;
    // cin >> n;

    // vector<vector<int>> jobs;
    vector<vector<int>> jobs = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};
    int n = jobs.size();
    int maxSlots = 0;
    for(auto job : jobs){
        maxSlots = max(maxSlots, job[1]);
    }

    // for(int i = 0;i<n;i++){
    //     int x,y,z;
    //     cin >> x >> y >> z;
    //     if(y>maxSlots)maxSlots = y;
    //     jobs.push_back({x,y,z});
    // }

    priority_queue<vector<int>,vector<vector<int>>> pq;

    for(auto job : jobs){
        // cout<<job[0]<<" "<<job[1]<<" "<<job[2]<<endl;
        pq.push({job[2],job[1]});
    }


    vector<int> slots(maxSlots+1,0);
    int job_count = 0;
    int total_profit = 0;
    while(!pq.empty()){
        auto job = pq.top();
        pq.pop();
        // cout<<job[0]<<" "<<job[1]<<endl;

        for(int i = job[1]-1;i>=0;i--){
            if(slots[i] == 0){
                slots[i] = job[0];
                job_count++;
                total_profit += job[0];
                break;
            }
        }
    }

    cout<<job_count<<" "<<total_profit<<endl;

    return 0;



    



}