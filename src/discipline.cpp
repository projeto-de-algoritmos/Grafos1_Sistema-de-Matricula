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
      d += toupper(line[i]);
    }
    for (j = pos + 1; j < (int) line.size(); j++) {
      if (line[j] == ',') {
        pos = j;
        break;
      }
      c += toupper(line[j]);
    }
    for (k = pos + 1; k < (int) line.size(); k++) {
      if (line[k] == ',') {
        pos = k;
        break;
      }
      prs += toupper(line[k]);
    }
    for (l = pos + 1; l < (int) line.size(); l++) {
      if (line[l] == ',') {
        pos = l;
        break;
      }
      cs += toupper(line[l]);
    }
    disciplines.push_back({d, stoi(c), prs, stoi(cs)});
    d = c = prs = cs = "";
  }
}

void Discipline::add(string _name, int _code, string _prerequisites, int _codes) {
  disciplines.push_back({_name, _code, _prerequisites, _codes});
}

void Discipline::show_disciplines() {
  get_disciplines_from_csv("data/disciplines.csv");
  cout << "\t\tAqui estão as disciplinas do CURRICULUM DE ENGENHARIA DE SOFTWARE (Nome e Código) da Universidade de Brasília!\n\n";
  for (int i = 0; i < (int) disciplines.size(); i++) {
    cout << disciplines[i].name << ": " << disciplines[i].code << '\n';
  }
}
