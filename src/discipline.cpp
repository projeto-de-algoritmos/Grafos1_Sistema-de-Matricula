#include <bits/stdc++.h>
#include "../inc/discipline.hpp"

using namespace std;

void Discipline::get_disciplines_from_csv(const string& path) {
  ifstream fp(path);
  if (!fp) {
    cout << "unable to open file!" << '\n';
  }
  int buffer = 100, pos = 0;
  fp.ignore(buffer, '\n');
  string line;
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
    disciplines.push_back({d, stoi(c), prs, stoi(cs)});
    d = c = prs = cs = "";
  }
}

void Discipline::add(string _name, int _code, string _prerequisites, int _codes) {
  disciplines.push_back({_name, _code, _prerequisites, _codes});
}

void Discipline::show_disciplines() {
  cout << "Nome" << " " << "Código" << '\n';
  for (int i = 0; i < (int) disciplines.size(); i++) {
    cout << disciplines[i].name << ": " << disciplines[i].code << '\n';
  }
}
