#ifndef DISCIPLINE_H
#define DISCIPLINE_H

class Discipline {
 public:
  string name;
  int code;
  string prerequisites;
  int codes;
  vector<Discipline> disciplines;

  Discipline() {}
  Discipline(string _name, int _code, string _prerequisites, int _codes) : name(_name),
             code(_code), prerequisites(_prerequisites), codes(_codes) {}
  ~Discipline() {}
  void get_disciplines_from_csv(const string& path);
  void add(string _name, int _code, string _prerequisites, int _codes);
  void show_disciplines(); 
};

#endif
