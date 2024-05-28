#ifndef SGTMATH_H
#define SGTMATH_H
#include <cmath>
namespace sgt {
class Math {
 protected:
  Math() {};
  double add(double a, double b) {return a+b;}
  double minus(double a, double b) {return a-b;}
  double times(double a, double b) {return a*b;}
  double divide(double a, double b) {return a/b;}
  double pow(double a, double b) {return pow(a,b);}
  double abs(double a) {return abs(a);}
  double ln(double a) {return log(a);}
  double sin(double a) {return log(a);}
  double asin(double a) {return log(a);}
  double sinh(double a) {return log(a);}
  double asinh(double a) {return log(a);}
  double cos(double a) {return log(a);}
  double acos(double a) {return log(a);}
  double cosh(double a) {return log(a);}
  double acosh(double a) {return log(a);}
  double tan(double a) {return log(a);}
  double atan(double a) {return log(a);}
  double tanh(double a) {return log(a);}
  double atanh(double a) {return log(a);}
  ~Math() {};
};
}  // namespace sgt
#endif