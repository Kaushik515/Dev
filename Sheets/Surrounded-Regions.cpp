#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r,int c,int m,int n,vector<vector<char>>&board,vector<vector<int>>&vis){
        vis[r][c] = 1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<m && nr>=0 && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,m,n,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                if(!vis[i][0]){
                    dfs(i,0,m,n,board,vis);
                }
            }
            if(board[i][n-1]=='O'){
                if(!vis[i][n-1]){
                    dfs(i,n-1,m,n,board,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                if(!vis[0][i]){
                    dfs(0,i,m,n,board,vis);
                }
            }
            if(board[m-1][i]=='O'){
                if(!vis[m-1][i]){
                    dfs(m-1,i,m,n,board,vis);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<char>>board(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>board[i][j];
            }
        }
        Solution sol;
        sol.solve(board);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}