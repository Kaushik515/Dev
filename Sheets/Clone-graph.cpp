#include "bits/stdc++.h"
using namespace std;
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;
    queue<Node *> q;
    q.push(node);
    Node *clone = new Node(node->val);
    map<Node *, Node *> mp;
    mp[node] = clone;
    while (!q.empty()) {
      auto it = q.front();
      q.pop();
      for (auto i : it->neighbors) {
        if (mp.find(i) == mp.end()) {
          Node *cloneNode = new Node(i->val);
          mp[i] = cloneNode;
          q.push(i);
        }
        mp[it]->neighbors.push_back(mp[i]);
      }
    }
    return clone;
  }
};
int main() {
  Solution sol;
  int n;
  cin >> n;
  vector<Node *> nodes(n);
  for (int i = 0; i < n; i++) {
    nodes[i] = new Node(i + 1);
  }
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int neighbor;
      cin >> neighbor;
      nodes[i]->neighbors.push_back(nodes[neighbor - 1]);
    }
  }
  Node *clone = sol.cloneGraph(nodes[0]);
  return 0;
}
// TC : O(V+E), SC : O(V+E)