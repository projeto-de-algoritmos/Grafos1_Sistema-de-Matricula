#ifndef DISCIPLINE_H
#define DISCIPLINE_H

class Discipline {
 public:
  string name;
  int code;
  string prerequisite1;
  int code1;
  string prerequisite2;
  int code2;

  Discipline() {}
  Discipline(string _name, int _code, string _prerequisite1, int _code1, string _prerequisite2, int _code2) : name(_name),
             code(_code), prerequisite1(_prerequisite1), code1(_code1), prerequisite2(_prerequisite2), code2(_code2) {}
  ~Discipline() {}
  vector<Discipline> read_file(const string& path);
};

#endif
