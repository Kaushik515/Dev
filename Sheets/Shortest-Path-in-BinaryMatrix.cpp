#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>>piii;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1)return -1;
        priority_queue<piii,vector<piii>,greater<piii>>pq;
        pq.push({1,{0,0}});
        grid[0][0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int move = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==n-1)return move;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = r + i;
                    int nc = c + j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                        grid[nr][nc] = 1;
                        pq.push({move+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
int main(){
    Solution sol;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        cout<<sol.shortestPathBinaryMatrix(grid)<<endl;
    }
}
//TC : O(n^2 log n) where n is the size of the grid.
//SC : O(n^2) for the priority queue and the grid.