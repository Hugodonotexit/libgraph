/*
MIT License

Copyright (c) 2024 Hugodonotexit

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

1.Attribution:
  All users of this Software must give appropriate credit to the original
creators. Such credit shall include, but not be limited to, the inclusion of the
following elements in any derived works, distributions, or publications: -The
name and version of the Software used. -A link to the original Software or the
original creator’s website (if applicable). -A clear statement that the work is
derived from or built with the Software. -The attribution must be placed in a
location that is reasonably conspicuous, ensuring that anyone using or
interacting with the derivative work is aware of the original creators'
contribution. 2.Commercial Use: Use of the Software for commercial purposes is
subject to prior approval by the original creators. Entities or individuals
wishing to use the Software for commercial gain must first seek and obtain
written permission from the copyright holders. The request for permission must
include: -A detailed description of the intended commercial use. -The expected
duration of such use. -Any potential modifications or derivatives to be created
from the Software. -Approval for commercial use is at the sole discretion of the
copyright holders and may be subject to specific terms and conditions as
stipulated at the time of approval. 3.Enforcement: Failure to comply with these
conditions will be considered a breach of the license and may result in
revocation of the rights granted under this License. The copyright holders
reserve the right to take any action deemed necessary to enforce compliance with
these terms, including legal proceedings.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef SGTMATH_H
#define SGTMATH_H
#include <cmath>
#include <stdexcept>
namespace sgt {
///////////////////////////////////////////////////////////////////////
//!!!FOR FUNCTION COMPILE ONLY, NOT RECOMMENDED TO USE IT DIRECTLY!!!//
///////////////////////////////////////////////////////////////////////
class Math {
 protected:
  Math() {};
  double add(double a, double b) {return a+b;}
  double minus(double a, double b) {return a-b;}
  double times(double a, double b) {return a*b;}
  double divide(double a, double b) {
    if (b == 0)
    {
      throw std::logic_error("ERROR_DIVIDED_BY_ZERO");
      return std::nan("");
    }
    return a/b;
    }
  double pow(double a, double b) {return std::pow(a,b);}
  double negative(double a) {return -a;}
  double abs(double a) {return std::fabs(a);}
  double ln(double a) {return std::log(a);}
  double sin(double a) {return std::sin(a);}
  double asin(double a) {return std::asin(a);}
  double sinh(double a) {return std::sinh(a);}
  double asinh(double a) {return std::asinh(a);}
  double cos(double a) {return std::cos(a);}
  double acos(double a) {return std::acos(a);}
  double cosh(double a) {return std::cosh(a);}
  double acosh(double a) {return std::acosh(a);}
  double tan(double a) {return std::tan(a);}
  double atan(double a) {return std::atan(a);}
  double tanh(double a) {return std::tanh(a);}
  double atanh(double a) {return std::atanh(a);}
  long factorial(int a) {
    if (a == 0)
    {
      return 1;
    }
    
    int x = 1;
    for (int i = 1; i <= a; i++)
    {
      x *= i;
    }
    return x;
  }
  ~Math() {};
};
}  // namespace sgt
#endif