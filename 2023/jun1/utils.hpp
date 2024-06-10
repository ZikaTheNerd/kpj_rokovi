#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <iostream>
using namespace std;

vector<double> saberi_vektore(const vector<double>&, const vector<double>&);
vector<double> oduzmi_vektore(const vector<double> &v1, const vector<double> &v2);
vector<double> pomnozi_skalarno(double d, const vector<double> &v2);
vector<double> negativni(const vector<double> &v1);
vector<double> vek_proizvod(const vector<double> &v1, const vector<double> &v2);
vector<double> koord_mnozi(vector<double> &v1, vector<double> &v2);
ostream &operator<<(ostream &os, const vector<double> &v);

#endif //UTILS_HPP
