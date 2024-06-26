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

#ifndef SGTVAR_H
#define SGTVAR_H
#include <vector>
#include <cstdint>
#include <vector>
#include <future>
namespace sgt {

// Structure representing a 2D vector with floating-point coordinates
struct Vectorlf {
  double x;
  double y;

  //Constructor
  Vectorlf() {x=0; y=0;}
  Vectorlf(double initX, double initY) : x(initX), y(initY) {}

  // Operator overload
  Vectorlf operator+(const Vectorlf& other) const {
    return Vectorlf(x + other.x, y + other.y);
  }
  Vectorlf operator-(const Vectorlf& other) const {
    return Vectorlf(x - other.x, y - other.y);
  }
  Vectorlf operator*(const Vectorlf& other) const {
    return Vectorlf(x * other.x, y * other.y);
  }
  Vectorlf operator/(const Vectorlf& other) const {
    return Vectorlf(x / other.x, y / other.y);
  }

  Vectorlf operator+(const double& other) const {
    return Vectorlf(x + other, y + other);
  }
  Vectorlf operator-(const double& other) const {
    return Vectorlf(x - other, y - other);
  }
  Vectorlf operator*(const double& other) const {
    return Vectorlf(x * other, y * other);
  }
  Vectorlf operator/(const double& other) const {
    return Vectorlf(x / other, y / other);
  }
};

// Alias representing a line segment
using LineSeg = std::pair<Vectorlf, Vectorlf>;

// Structure representing a color with RGBA components
struct Colour {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t t;

  // Default constructor initializing color to black
  Colour() : r(0), g(0), b(0), t(255) {}
  // Constructor to initialize color with specified RGBA values
  Colour(double r, double g, double b, double t) : r(r), g(g), b(b), t(t) {}
  
  // Static methods to create common colors
  static Colour Black(int t = 255)     { return Colour(0, 0, 0, t); }
  static Colour White(int t = 255)     { return Colour(255, 255, 255, t); }
  static Colour Red(int t = 255)       { return Colour(255, 0, 0, t); }
  static Colour Lime(int t = 255)      { return Colour(0, 255, 0, t); }
  static Colour Blue(int t = 255)      { return Colour(0, 0, 255, t); }
  static Colour Yellow(int t = 255)    { return Colour(255, 255, 0, t); }
  static Colour Cyan(int t = 255)      { return Colour(0, 255, 255, t); }
  static Colour Magenta(int t = 255)   { return Colour(255, 0, 255, t); }
  static Colour Silver(int t = 255)    { return Colour(192, 192, 192, t); }
  static Colour Gray(int t = 255)      { return Colour(128, 128, 128, t); }
  static Colour Maroon(int t = 255)    { return Colour(128, 0, 0, t); }
  static Colour Olive(int t = 255)     { return Colour(128, 128, 0, t); }
  static Colour Green(int t = 255)     { return Colour(0, 128, 0, t); }
  static Colour Purple(int t = 255)    { return Colour(128, 0, 128, t); }
  static Colour Teal(int t = 255)      { return Colour(0, 128, 128, t); }
  static Colour Navy(int t = 255)      { return Colour(0, 0, 128, t); }  

};
}  // namespace sgt

#endif