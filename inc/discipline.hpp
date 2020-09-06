#ifndef DISCIPLINE_H
#define DISCIPLINE_H

class Discipline {
 public:
  string name;
  int code;
  string prerequisites;
  int codes;

  Discipline() {}
  Discipline(string _name, int _code, string _prerequisites, int _codes) : name(_name),
             code(_code), prerequisites(_prerequisites), codes(_codes) {}
  ~Discipline() {}
  vector<Discipline> read_file(const string& path);
};

#endif
