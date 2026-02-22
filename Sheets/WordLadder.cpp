#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    set<string> st;
    for (string s : wordList)
      st.insert(s);
    if (st.find(endWord) == st.end())
      return 0;
    while (!q.empty()) {
      auto it = q.front();
      q.pop();
      string s = it.first;
      int seq = it.second;
      if (s == endWord)
        return seq;
      for (int i = 0; i < s.size(); i++) {
        string str = s;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          str[i] = ch;
          if (st.find(str) != st.end()) {
            st.erase(str);
            q.push({str, seq + 1});
          }
        }
      }
    }
    return 0;
  }
};
int main() {
  Solution sol;
  int t;
  cin >> t;
  while (t--) {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
      cin >> wordList[i];
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
  }
  return 0;
}
// TC : O(N*L*26), SC : O(N)