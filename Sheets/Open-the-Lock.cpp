#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
      return -1;
    if (target == "0000")
      return 0;

    unordered_set<string> beginSet{"0000"};
    unordered_set<string> endSet{target};
    unordered_set<string> visited{"0000"};

    int steps = 0;

    while (!beginSet.empty() && !endSet.empty()) {
      if (beginSet.size() > endSet.size())
        swap(beginSet, endSet);
      unordered_set<string> temp;
      steps++;
      for (string curr : beginSet) {
        for (int i = 0; i < 4; i++) {
          string next = curr;

          // rotate forward
          next[i] = (curr[i] - '0' + 1) % 10 + '0';
          if (endSet.count(next))
            return steps;
          if (!dead.count(next) && !visited.count(next)) {
            visited.insert(next);
            temp.insert(next);
          }

          // rotate backward
          next = curr;
          next[i] = (curr[i] - '0' + 9) % 10 + '0';
          if (endSet.count(next))
            return steps;
          if (!dead.count(next) && !visited.count(next)) {
            visited.insert(next);
            temp.insert(next);
          }
        }
      }

      beginSet = temp;
    }

    return -1;
  }
};
//TC : sqrt(1e4) operations
//SC : 1e4

// brute force
//  class Solution {
//  public:
//      int openLock(vector<string>& deadends, string target) {
//          set<string>vis;
//          for(auto s : deadends)vis.insert(s);
//          if(vis.count("0000"))return -1;
//          queue<pair<int,string>>q;
//          q.push({0,"0000"});
//          vis.insert("0000");
//          while(!q.empty()){
//              auto it = q.front();
//              q.pop();
//              int move = it.first;
//              string curr = it.second;
//              if(curr == target){
//                  return move;
//              }
//              string temp = curr;
//              for(int i=0;i<4;i++){
//                  int num = temp[i]-'0';
//                  num = (num+1)%10;
//                  temp[i] = num+'0';
//                  if(vis.find(temp)==vis.end()){
//                      vis.insert(temp);
//                      q.push({move+1,temp});
//                  }
//                  temp = curr;
//                  num = temp[i]-'0';
//                  num = (num+9)%10;
//                  temp[i] = num+'0';
//                  if(vis.find(temp)==vis.end()){
//                      vis.insert(temp);
//                      q.push({move+1,temp});
//                  }
//                  temp = curr;
//              }
//          }
//          return -1;
//      }
//  };
//TC : 1e4 operations
//SC : 1e4
int main() {
  Solution sol;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> deadends(n);
    for (int i = 0; i < n; i++) {
      cin >> deadends[i];
    }
    string target;
    cin >> target;
    cout << sol.openLock(deadends, target) << endl;
  }
  return 0;
}
