#include <bits/stdc++.h>
#include "../inc/graph.hpp"
#include "../inc/discipline.hpp"

using namespace std;

void Graph::new_vertex() {
  g.resize(_size + 1);
  _size++;
}

void Graph::add(int to, int from) {
  g[to].push_back(from);
}

void Graph::assign_idx_to_disciplines() {
  Discipline d;
  d.get_disciplines_from_csv("data/disciplines.csv");
  for (int i = 0; i < (int) d.disciplines.size(); i++) {
    if (d.disciplines[i].name == "null") {
      continue;
    }
    mdisciplines[i] = {d.disciplines[i].name, d.disciplines[i].code};
  }
}

void Graph::assign_idx_to_prerequisites() {
  Discipline d;
  d.get_disciplines_from_csv("data/disciplines.csv");
  for (int i = 0; i < (int) d.disciplines.size(); i++) {
    if (d.disciplines[i].prerequisites == "null") {
      continue;
    }
    mprerequisites[i] = {d.disciplines[i].prerequisites, d.disciplines[i].codes};
  }
}

void Graph::show() {
  cout << "AQUI ESTÁ O GRAFO COM AS DISCIPLINAS E OS PREREQUISITOS" << "\n\n\n";
  for (int v = 0; v < _size; v++) {
    if (mdisciplines[v].first == "") {
        continue;
    }
    cout << "[" << mdisciplines[v].first << "] ->";
    for (int u : g[v]) {
      cout << " [" << mdisciplines[u].first << "]";
    }
    cout << '\n';
  }
}

vector<int> Graph::connectivity_level(int v) {
  vector<int> w(_size, 0);
  vector<int> neigh = g[v];
  for (int i : neigh) {
    w[i]++;
  }
  return w;
}

void Graph::dfs(int v, vector<bool> vis) {
  vis[v] = false;
  prerequisites.emplace_back(v); // prerequisites of a discipline (way to reach the discipline)
  for (int u : g[v]) {
    if (!vis[u]) {
      dfs(u, vis);
    }
  }
}

void Graph::bfs(int v, vector<bool> vis) {
  for (int i = 0; i < (int) vis.size(); i++) {
    vis[i] = false;
  }
  queue<int> q;
  q.push(v);
  vis[v] = true;
  while (not q.empty()) {
    auto x = q.front();
    prerequisites.emplace_back(x);
    q.pop();
    for (int u : g[x]) {
      if (!vis[u]) {
        q.push(u);
        vis[u] = true;
      }
    }
  }
}

bool Graph::is_reachable(int s, int t, vector<bool> vis) {
  for (int i = 0; i < (int) vis.size(); i++) {
    vis[i] = false;
  }
  if (s == t) {
    return true;
  }
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (not q.empty()) {
    auto x = q.front();
    q.pop();
    for (int u : g[x]) {
      if (u == t) {
        return true;
      }
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
      }
    }
  }
  return false;
}
