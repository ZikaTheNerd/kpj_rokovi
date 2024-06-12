#include "complex.hpp"

void ispisv(const vector<Complex> &v) {
  for (const auto &c : v) {
    c.ispis();
    cout << endl;
  }
}
