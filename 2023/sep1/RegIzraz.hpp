#ifndef REGIZRAZ_HPP
#define REGIZRAZ_HPP

#include <set>
#include <string>
#include <iostream>

using namespace std;

class RegIzraz {
public:
    virtual ~RegIzraz() { };
    void virtual ispis() const = 0;
    bool virtual check(const string &s) const = 0;
};

class Konstanta : public RegIzraz {
public:
    ~Konstanta() = default;
    Konstanta(char c) {
        konst = string(1, c);
    };
    void ispis() const;
    bool check(const string &s) const;
private:
    string konst;
};

class KarakKlasa : public RegIzraz {
public:
    ~KarakKlasa() = default;
    KarakKlasa(const string &s);
    void ispis() const;
    bool check(const string &s) const;
private:
    set<char> karakteri;
};

class Konkatenacija : public RegIzraz {
public:
    ~Konkatenacija();
    Konkatenacija(RegIzraz *r1, RegIzraz *r2) : r1(r1), r2(r2) {}
    void ispis() const;
    bool check(const string &s) const;
private:
    RegIzraz *r1;
    RegIzraz *r2;
};
class Disjunkcija : public RegIzraz {
public:
    ~Disjunkcija();
    Disjunkcija(RegIzraz *r1, RegIzraz *r2) : r1(r1), r2(r2) {}
    void ispis() const;
    bool check(const string &s) const;
private:
    RegIzraz *r1;
    RegIzraz *r2;
};
class Zvezda : public RegIzraz {
public:
    ~Zvezda();
    Zvezda(RegIzraz *r) : r(r) {}
    void ispis() const;
    bool check(const string &s) const;
private:
    RegIzraz *r;
};
class Plus : public RegIzraz {
public:
    ~Plus();
    Plus(RegIzraz *r) : r(r) {}
    void ispis() const;
    bool check(const string &s) const;
private:
    RegIzraz *r;
};

#endif //REGIZRAZ_HPP
