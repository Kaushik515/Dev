#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>q;
        q.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!q.empty()){
            auto [t,node] = q.front();
            q.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int time = it.second;
                if(dist[adjNode] > t + time){
                    dist[adjNode] = t+time;
                    q.push({t+time,adjNode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>times(m,vector<int>(3));
    for(int i=0;i<m;i++){     
        for(int j=0;j<3;j++){
            cin>>times[i][j];
        }
    }
    Solution sol;
    cout<<sol.networkDelayTime(times,n,k)<<endl;
}
//TC : O(ElogV) where E is the number of edges and V is the number of vertices in the graph.
//SC : O(V) where V is the number of vertices in the graph.