#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,k}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int t = it.second.first;
            int stops = it.second.second;
            if(stops < 0)continue;
            for(auto i : adj[node]){
                int adjNode = i.first;
                int time = i.second;
                if((dist[adjNode] > t+time) && stops>=0){
                    dist[adjNode] = t+time;
                    q.push({adjNode,{t+time,stops-1}});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
int main(){
    int n,m,src,dst,k;
    cin>>n>>m>>src>>dst>>k;
    vector<vector<int>>flights(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>flights[i][j];
        }
    }
    Solution sol;
    cout<<sol.findCheapestPrice(n, flights, src, dst, k)<<endl;
    return 0;
}
//TC : O(ElogV) where E is the number of edges and V is the number of vertices in the graph.
//SC : O(V) where V is the number of vertices in the graph.