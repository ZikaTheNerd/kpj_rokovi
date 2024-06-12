#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Complex {
public:
  Complex(int a = 0, int b = 0) : realni(a), imaginarni(b) {}

  void ispis() const { cout << realni << " + " << imaginarni << "i" << endl; }

  Complex operator+(const Complex &other) const {
    return Complex(realni + other.realni, imaginarni + other.imaginarni);
  }

  Complex operator-(const Complex &other) const {
    return Complex(realni - other.realni, imaginarni - other.imaginarni);
  }

  Complex conjugate() const { return Complex(realni, -imaginarni); }
  double abs() const {
    return sqrt(realni * double(realni) + imaginarni * double(imaginarni));
  }

  bool operator==(const Complex &other) const {
    return realni == other.realni && imaginarni == other.imaginarni;
  }

  Complex operator-() const {
    return Complex(-realni, -imaginarni);
  }

private:
  int realni;
  int imaginarni;
};
void ispisv(const vector<Complex> &v);

#endif //COMPLEX_HPP

