#include <bits/stdc++.h>
#include "../inc/discipline.hpp"

using namespace std;

vector<Discipline> Discipline::read_file(const string& path) {
  ifstream fp(path);
  if (!fp) {
    cout << "unable to open file!" << '\n';
  }
  int buffer = 100, pos = 0;
  fp.ignore(buffer, '\n');
  string line;
  vector<Discipline> dis;
  string d, c, prs, cs;
  int j = 0, k = 0, l = 0;
  while (getline(fp, line, '\n')) {
    for (int i = 0; i < (int) line.size(); i++) {
      if (line[i] == ',') {
        pos = i;
        break;
      }
      d += line[i];
    }
    for (j = pos + 1; j < (int) line.size(); j++) {
      if (line[j] == ',') {
        pos = j;
        break;
      }
      c += line[j];
    }
    for (k = pos + 1; k < (int) line.size(); k++) {
      if (line[k] == ',') {
        pos = k;
        break;
      }
      prs += line[k];
    }
    for (l = pos + 1; l < (int) line.size(); l++) {
      if (line[l] == ',') {
        pos = l;
        break;
      }
      cs += line[l];
    }
    dis.push_back({d, stoi(c), prs, stoi(cs)});
    d = c = prs = cs = "";
  }
  return dis;
}
