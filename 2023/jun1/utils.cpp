#include <iostream>

#include "utils.hpp"

vector<double> saberi_vektore(const vector<double> &v1,
                              const vector<double> &v2) {
  if (v1.size() != v2.size()) {
    cout << "Vektori razlicite velicine\n";
    return {};
  }

  int n = v1.size();
  vector<double> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = v1[i] + v2[i];
  }

  return result;
}

vector<double> oduzmi_vektore(const vector<double> &v1,
                              const vector<double> &v2) {
  if (v1.size() != v2.size()) {
    cout << "Vektori razlicite velicine\n";
    return {};
  }

  int n = v1.size();
  vector<double> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = v1[i] - v2[i];
  }

  return result;
}

vector<double> negativni(const vector<double> &v1) {
  int n = v1.size();
  vector<double> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = -v1[i];
  }

  return result;
}

ostream &operator<<(ostream &os, const vector<double> &v) {
  if (v.size() == 0) {
    os << "Vektor je prazan" << endl;
    return os;
  }

  vector<double>::const_iterator cit = v.cbegin();
  for (; cit < v.end() - 1; cit++) {
    os << *cit << ", ";
  }
  os << *cit << endl;
  return os;
}
vector<double> pomnozi_skalarno(double d, const vector<double> &v1) {
  int n = v1.size();
  vector<double> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = d * v1[i];
  }

  return result;
}

vector<double> vek_proizvod(const vector<double> &v1,
                            const vector<double> &v2) {
  return {v1[1] * v2[2] - v1[2] * v2[1], v1[2] * v2[0] - v1[0] * v2[2],
          v1[0] * v2[1] - v1[1] * v2[0]};
}
vector<double> koord_mnozi(vector<double> &v1, vector<double> &v2) {
  if (v1.size() < v2.size()) {
    v1.resize(v2.size(), 1.0);
  }
  v2.resize(v1.size(), 1.0);

  int n = v1.size();
  vector<double> result(n);
  for (int i = 0; i < n; i++) {
    result[i] = v1[i] * v2[i];
  }

  return result;
}
