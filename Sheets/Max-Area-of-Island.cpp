#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int bfs(vector<vector<int>>&grid,int r,int c){
        int m = grid.size();
        int n = grid[0].size();
        int area = 1;
        grid[r][c] = 0;
        queue<pair<int,int>>q;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        q.push({r,c});
        while(!q.empty()){
            auto [r,c] =q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc<n && nc>=0 && grid[nr][nc]==1){
                    q.push({nr,nc});
                    area++;
                    grid[nr][nc] = 0;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxArea = max(maxArea,bfs(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};
int main(){
    Solution sol;
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        cout<<sol.maxAreaOfIsland(grid)<<'\n';
    }
    return 0;
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)