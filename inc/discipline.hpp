#ifndef DISCIPLINE_H
#define DISCIPLINE_H

class Discipline {
 public:
  string name;
  int code;

  Discipline() {}
  Discipline(string _name, int _code) : name(_name), code(_code) {}
  ~Discipline() {}
  vector<Discipline> read_file(const string& path);
};

#endif
