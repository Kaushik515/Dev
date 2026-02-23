#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(auto it:prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int num = q.front();
            q.pop();
            ans.push_back(num);
            for(auto it:adj[num]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses)return ans;
        else return {};
    }
};
int main(){
    Solution sol;
    int t;
    cin>>t;
    while(t--){
        int numCourses,m;
        cin>>numCourses>>m;
        vector<vector<int>>prerequisites(m,vector<int>(2));
        for(int i=0;i<m;i++){
            for(int j=0;j<2;j++){
                cin>>prerequisites[i][j];
            }
        }
        vector<int>ans = sol.findOrder(numCourses,prerequisites);
        if(ans.size()==0){
            cout<<"No valid order exists\n";
        }else{
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}