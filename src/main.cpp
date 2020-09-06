#include <bits/stdc++.h>
#include "../inc/discipline.hpp"
#include "../inc/graph.hpp"

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 50;
  Graph g(N);
  g.assign_idx_to_disciplines();
  g.assign_idx_to_prerequisites();
  g.add(5, 0); g.add(9, 0); g.add(10, 5);
  g.add(13, 8); g.add(14, 8); g.add(15, 1);
  g.add(17, 11); g.add(18, 15); g.add(19, 1);
  g.add(20, 13); g.add(21, 16); g.add(22, 15);
  g.add(23, 18); g.add(24, 18); g.add(25, 21);
  g.add(26, 20); g.add(27, 19); g.add(28, 19);
  g.add(29, 23); g.add(30, 18); g.add(31, 24);
  g.add(32, 26); g.add(33, 25); g.add(34, 0);
  g.add(35, 30); g.add(36, 15); g.add(37, 26);
  g.add(38, 32); g.add(39, 35); g.add(40, 30);
  g.add(42, 22); g.add(44, 43);
  vector<bool> vis(N, false);
  cout << "\n";
  for (int i = 0; i < (int) g.prerequisites.size(); i++) {
    if (g.mprerequisites[g.prerequisites[i]].first == "") {
      continue;
    }
    cout << g.mprerequisites[g.prerequisites[i]].first << '\n';
  }
  return 0;
}

