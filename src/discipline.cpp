#include <bits/stdc++.h>
#include "../inc/discipline.hpp"

using namespace std;

vector<Discipline> Discipline::read_file(const string& path) {
  ifstream fp(path);
  if (!fp) {
    cout << "unable to open file!" << '\n';
  }
  int buffer = 40, pos = 0;
  fp.ignore(buffer, '\n');
  string line;
  vector<Discipline> dis;
  string _s, _c;
  while (getline(fp, line, '\n')) {
    for (int i = 0; i < (int) line.size(); i++) {
      if (line[i] == ',') {
        pos = i;
        break;
      }
      _s += line[i];
    }
    for (int j = pos + 1; j < (int) line.size(); j++) {
      if (line[j] == '\0') {
        break;
      }
      _c += line[j];
    }
    dis.push_back({_s, stoi(_c)});
    _s = _c = "";
  }
  return dis;
}
