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
  string d, c, pr1, c1, pr2, c2;
  int j = 0, k = 0, l = 0, p = 0, x = 0;
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
      pr1 += line[k];
    }
    for (l = pos + 1; l < (int) line.size(); l++) {
      if (line[l] == ',') {
        pos = l;
        break;
      }
      c1 += line[l];
    }
    for (p = pos + 1; p < (int) line.size(); p++) {
      if (line[p] == ',') {
        pos = p;
        break;
      }
      pr2 += line[p];  
    }
    for (x = pos + 1; x < (int) line.size(); x++) {
      if (line[x] == '\0') {
        break;
      }
      c2 += line[x];  
    }
    dis.push_back({d, stoi(c), pr1, stoi(c1), pr2, stoi(c2)});
    d = c = pr1 = c1 = pr2 = c2 = "";
  }
  return dis;
}