#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void dfs(int r,int c,int m,int n,vector<vector<char>>&grid){
        grid[r][c] = '0';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1'){
                dfs(nr, nc, m, n, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,m,n,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main(){
    Solution sol;
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<char>>grid(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        cout<<sol.numIslands(grid)<<'\n';
    }
    return 0;
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)