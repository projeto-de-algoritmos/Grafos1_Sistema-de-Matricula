#include <bits/stdc++.h>
#include "../inc/discipline.hpp"
#include "../inc/graph.hpp"

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Discipline d1;
  auto x = d1.read_file("data/disciplines.csv");
  map<int, pair<string, int>> disciplines;
  map<int, pair<string, int>> prerequisites;
  for (int i = 0; i < (int) x.size(); i++) {
    disciplines[i] = {x[i].name, x[i].code};
  }
  for (int i = 0; i < (int) x.size(); i++) {
    prerequisites[i] = {x[i].prerequisites, x[i].codes};
  }
  // for (auto [k, v] : disciplines) {
  //   cout << k << " " << v.first << " " << v.second << "\n";
  // }
  // cout << "\n";
  // for (auto [k, v] : prerequisites) {
  //   cout << k << " " << v.first << " " << v.second << "\n";
  // }
  for (auto [k, v] : prerequisites) {
    cout << k << " " << v.first << " " << v.second << "\n";
  }
  Graph g(46);
  g.add(5, 0);
  g.add(9, 0);
  g.add(10, 5);
  g.add(13, 8);
  g.add(14, 8);
  g.add(15, 1);
  g.add(17, 11);
  g.add(18, 15);
  g.add(19, 1);
  g.add(20, 13);
  g.add(21, 16);
  g.add(22, 15);
  g.add(23, 18);
  g.add(24, 18);
  g.add(25, 21);
  g.add(26, 20);
  g.add(27, 19);
  g.add(28, 19);
  g.add(29, 23);
  g.add(30, 18);
  g.add(31, 24);
  g.add(32, 26);
  g.add(33, 25);
  g.add(34, 0);
  g.add(35, 30);
  g.add(36, 15);
  g.add(37, 26);
  g.add(38, 32);
  g.add(39, 35);
  g.add(40, 30);
  g.add(42, 22);
  g.add(44, 43);
  g.show();
  cout << "Olá, como está? Essas aqui são as matérias de software" << '\n';
  for (auto [idx, s] : disciplines) {
    cout << idx << ": " << s.first << " " << s.second << "\n";
  }
  cout << "Entre com o índice da disciplina (1..45): ";
  int input;
  cin >> input;
  cout << "Esse aqui é o fluxo da matéria " << disciplines[input].first << "\n";
  vector<bool> vis(45, false);
  g.dfs(input, vis);
  reverse(g.prerequisites.begin(), g.prerequisites.end());
  for (auto d : g.prerequisites) {
    if (prerequisites[d].first == "null") {
      continue;
    }
    cout << prerequisites[d].first << " " << prerequisites[d].second << "\n";
  }
  return 0;
}

