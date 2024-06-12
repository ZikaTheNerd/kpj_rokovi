#include "naredbe.hpp"
#include "complex.hpp"

using namespace std;

void SNaredba::izvrsi() const { cout << msg << endl; }

void ANaredba::izvrsi() const {
  cout << "Elementi niza " << ime << " su:" << endl;
  ispisv(niz);
}

void UslovNaredba::izvrsi() const {
  if (uslov) {
    for (const auto &naredba : *naredbe1) {
      naredba->izvrsi();
    }
  } else {
    for (const auto &naredba : *naredbe2) {
      naredba->izvrsi();
    }
  }
}
