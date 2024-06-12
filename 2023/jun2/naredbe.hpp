#ifndef NAREDBE_HPP
#define NAREDBE_HPP

#include <string>
#include <vector>

#include "complex.hpp"

using namespace std;

class Naredba {
public:
  virtual void izvrsi() const = 0;
  virtual ~Naredba() {}
};

class SNaredba : public Naredba {
private:
  string msg;

public:
  SNaredba(string msg) : msg(msg) {}

  void izvrsi() const;
  ~SNaredba() = default;
};

class ANaredba : public Naredba {
private:
  vector<Complex> niz;
  string ime;

public:
  ANaredba(const vector<Complex> &niz, const string &ime)
      : niz(niz), ime(ime) {}

  void izvrsi() const;
  ~ANaredba() = default;
};

class UslovNaredba : public Naredba {
private:
  bool uslov;
  const vector<Naredba *> *naredbe1;
  const vector<Naredba *> *naredbe2;

public:
  void izvrsi() const;
  UslovNaredba(bool uslov, const vector<Naredba *> *naredbe1,
               const vector<Naredba *> *naredbe2)
      : uslov(uslov), naredbe1(naredbe1), naredbe2(naredbe2) {}
  ~UslovNaredba() {
    for (const auto &naredba : *naredbe1) {
      delete naredba;
    }
    for (const auto &naredba : *naredbe2) {
      delete naredba;
    }
    delete naredbe1;
    delete naredbe2;
  }
};

#endif // NAREDBE_HPP
