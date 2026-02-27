#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;
            int prevh = heights[r][c];
            if(r==n-1 && c==m-1)return cost;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int currh = heights[nr][nc];
                    int newEffort = max(cost,abs(currh-prevh));
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>heights(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>heights[i][j];
        }
    }
    cout<<s.minimumEffortPath(heights)<<endl;
    return 0;
}
// Time Complexity: O(n*m*log(n*m)) where n and m are the dimensions of the grid.
// Space Complexity: O(n*m) for the distance matrix and the priority queue.