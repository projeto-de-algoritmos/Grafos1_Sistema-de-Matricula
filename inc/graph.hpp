#ifndef GRAPH_H
#define GRAPH_H

class Graph {
 public:
  vector<vector<int>> g;
  int _size;
  vector<int> disciplines;
  vector<int> prerequisites;
  map<int, pair<string, int>> mdisciplines;
  map<int, pair<string, int>> mprerequisites;

  Graph(int s) : _size(s) {
    g.resize(s);
  };
  void new_vertex();
  void add(int to, int from);
  void assign_idx_to_disciplines();
  void assign_idx_to_prerequisites();
  void show();
  vector<int> connectivity_level(int v); 
  void dfs(int v, vector<bool> vis);
  void bfs(int v, vector<bool> vis);
  bool is_reachable(int s, int t, vector<bool> vis);
};

#endif
