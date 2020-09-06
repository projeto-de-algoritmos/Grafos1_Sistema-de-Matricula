#include <bits/stdc++.h>
#include "../inc/graph.hpp"

using namespace std;

Graph::Graph(int __size) {
  _size = __size;
  g.resize(__size);
}

void Graph::new_vertex() {
  g.resize(_size + 1);
  _size++;
}

void Graph::show() {
  for (int v = 0; v < _size; v++) {
    cout << v << "->";
    for (int u : g[v]) {
      cout << " " << u;
    }
    cout << '\n';
  }
}

void Graph::add(int to, int from) {
  g[to].push_back(from);
}

void Graph::dfs(int v, vector<bool> vis) {
  vis[v] = false;
  prerequisites.emplace_back(v);
  for (int u : g[v]) {
    if (!vis[u]) {
      dfs(u, vis);
    }
  }
}
