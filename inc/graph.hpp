#ifndef GRAPH_H
#define GRAPH_H

class Graph {
 public:
  vector<vector<int>> g;
  int _size;
  vector<int> disciplines;
  vector<int> prerequisites;

  Graph(int __size);
  void new_vertex();
  void add(int to, int from);
  void show();
  void dfs(int u, vector<bool> vis);
};

#endif
