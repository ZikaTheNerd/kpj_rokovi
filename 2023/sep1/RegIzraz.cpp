#include <vector>
#include "RegIzraz.hpp"

void Konstanta::ispis() const {
    cout << konst;
}

KarakKlasa::KarakKlasa(const string &s) {
    for(size_t i = 1; i < s.length() - 1; i++) {
        karakteri.insert(s[i]);
    }
}

void KarakKlasa::ispis() const {
    if (karakteri.size() == 0) {
        cout << "";
        return;
    }

    vector<char> za_ispis(karakteri.begin(), karakteri.end());

    auto it = za_ispis.begin();
    while (it != za_ispis.end() - 1) {
        cout << *it << "|";
        it++;
    }
    cout << *it;
}

Disjunkcija::~Disjunkcija() {
    delete r1;
    delete r2;
}

void Disjunkcija::ispis() const {
    cout << "(";
    r1->ispis();
    cout << ")|(";
    r2->ispis();
    cout << ")";
}

Konkatenacija::~Konkatenacija() {
    delete r1;
    delete r2;
}

void Konkatenacija::ispis() const {
    r1->ispis();
    r2->ispis();
}

Zvezda::~Zvezda() {
    delete r;
}

void Zvezda::ispis() const {
    cout << "(";
    r->ispis();
    cout << ")*";
}

Plus::~Plus() {
    delete r;
}

void Plus::ispis() const {
    cout << "(";
    r->ispis();
    cout << ")+";
}


