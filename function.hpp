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
#ifndef SGTFUNCTION_H
#define SGTFUNCTION_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

#include "math.hpp"
#include "var.hpp"
namespace sgt {
class Func : public sgt::Math {
 private:
  std::string _function;
  using varsFunc = std::variant<double, char>;
  std::vector<varsFunc> function;
  std::vector<std::pair<size_t, size_t>> bracket;
  std::vector<Vectorlf> point;
  void checkFunc();

  void scanFunc();
  void cleanNAN();
  void locateBrackets();
  void locateOps();

  void pushFunc();
  bool isValidCharacter(char c);

 public:
  Func();
  Func(std::string _function);
  void setFunc(std::string _function);
  std::string getFunc() const;
  double get_y(double x);
  ~Func();
};

bool Func::isValidCharacter(char c) {
  static const std::unordered_set<char> validChars = {
      '.', '0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', '+', '-', '*', '^', '!', 'x', 'e', 'a', 'h',
      'i', 'l', 'n', 'o', 'p', 's', 't', '|', '(', ')'};
  return validChars.find(c) != validChars.end();
}

Func::Func(){};
Func::Func(std::string _function) { setFunc(_function); }
void Func::setFunc(std::string _function) {
  this->_function = _function;
  try {
    checkFunc();
  } catch (const std::logic_error& e) {
    std::cerr << "Undefined function!!! " << e.what() << std::endl;
    _function = "NULL";
    function.erase(function.begin(), function.end());
    return;
  }
  pushFunc();
};
std::string Func::getFunc() const { return _function; };
Func::~Func(){};

void Func::checkFunc() {
  if (_function[0] == '/' || _function[0] == '*' || _function[0] == '^' ||
      _function[0] == '!') {
    throw std::logic_error("ERROR00a");
    return;
  }
  if (_function[_function.size() - 1] == '/' ||
      _function[_function.size() - 1] == '*' ||
      _function[_function.size() - 1] == '+' ||
      _function[_function.size() - 1] == '^' ||
      _function[_function.size() - 1] == '!' ||
      _function[_function.size() - 1] == '-') {
    throw std::logic_error("ERROR00b");
    return;
  }

  for (size_t i = 0; i < _function.size(); i++) {
    if (_function.size() > 1 && _function[i] == '(' &&
        (_function[i + 1] == '/' || _function[i + 1] == '*' ||
         _function[i + 1] == '^' || _function[i + 1] == '!')) {
      throw std::logic_error("ERROR00c");
      return;
    }
    if (!isValidCharacter(_function[i])) {
      throw std::logic_error("ERROR00d");
    }
  }
};

void Func::scanFunc() {
  cleanNAN();
  locateBrackets();
  locateOps();
}
void Func::cleanNAN() {
  for (size_t i = 0; i < function.size(); i++) {
    if (std::holds_alternative<double>(function[i])) {
      if (std::isnan(std::get<double>(function[i]))) {
        function.erase(function.begin() + i);
        i--;
      }
    }
  }
};

void Func::locateBrackets() {
  bracket.erase(bracket.begin(), bracket.end());
  std::vector<size_t> openBracket, closeBracket;
  for (int i = 0; i < (int)function.size(); i++) {
    if (std::holds_alternative<char>(function[i])) {
      if (std::get<char>(function[i]) == '(') {
        openBracket.push_back(i);
      } else if (std::get<char>(function[i]) == ')') {
        closeBracket.push_back(i);
      }
      std::cout << i << std::endl;
    }
  }
  if (openBracket.size() != closeBracket.size()) {
    throw std::logic_error("ERROR01a");
    return;
  }
  for (int i = (int)openBracket.size() - 1; i >= 0; i--) {
    if (openBracket[i] >= closeBracket[i]) {
      throw std::logic_error("ERROR01b");
      return;
    }
  }
  for (int i = 0; i < (int)openBracket.size(); i++) {
    for (int j = closeBracket.size(); j >= 0; j--) {
      bracket.push_back(std::make_pair(openBracket[i], closeBracket[j]));
    }
  }
}

void Func::locateOps() {}

void Func::pushFunc() {
  bool isNum = false;
  size_t numCharStart;

  for (size_t i = 0; i < _function.size(); i++) {
    if ((std::isdigit(_function[i]) || _function[i] == '.') && !isNum) {
      isNum = true;
      numCharStart = i;
      continue;
    } else if (!(std::isdigit(_function[i]) || _function[i] == '.') && isNum) {
      isNum = false;
      double num = std::stod(_function.substr(numCharStart, i - numCharStart));
      function.push_back(num);
      continue;
    } else if ((std::isdigit(_function[i]) || _function[i] == '.') && isNum) {
      continue;
    }
    function.push_back(_function[i]);
  }
  if (isNum) {
    double num = std::stod(
        _function.substr(numCharStart, _function.size() - numCharStart));
    function.push_back(num);
  }
};

double Func::get_y(double x) {
  for (size_t i = 0; i < function.size(); i++) {
    if (std::holds_alternative<char>(function[i])) {
      if (std::get<char>(function[i]) == 'x') {
        function[i] = x;
      } else if (std::get<char>(function[i]) == 'e') {
        function[i] = 2.718281828459045;
      } else if (std::get<char>(function[i]) == 'p' &&
                 std::get<char>(function[i + 1]) == 'i') {
        function[i] = 3.1415926535897932;
        function[i + 1] = std::nan("");
      }
    };
  }
  scanFunc();
  for (int j = bracket.size() - 1; j >= 0; j--) {
    for (int i = (int)bracket[j].first + 1; i < (int)bracket[j].second - 1;
         i++) {
      if (std::holds_alternative<char>(function[i]) &&
          std::holds_alternative<char>(function[i - 1]) &&
          std::holds_alternative<double>(function[i + 1])) {
        switch (std::get<char>(function[i])) {
          case '-':
            function[i] = std::nan("");
            function[i + 1] = negative(std::get<double>(function[i + 1]));
            break;

          case '+':
            function[i] = std::nan("");
            break;
          default:
            throw std::logic_error("ERROR02");
            break;
        }
      } else if (std::holds_alternative<char>(function[i]) &&
                 std::holds_alternative<double>(function[i - 1]) &&
                 std::holds_alternative<double>(function[i + 1])) {
        switch (std::get<char>(function[i])) {
          case '+':
            function[i] = add(std::get<double>(function[i - 1]),
                              std::get<double>(function[i + 1]));
            function[i + 1] = std::nan("");
            function[i - 1] = std::nan("");
            break;
          case '-':
            function[i] = minus(std::get<double>(function[i - 1]),
                                std::get<double>(function[i + 1]));
            function[i + 1] = std::nan("");
            function[i - 1] = std::nan("");
            break;
          case '*':
            function[i] = times(std::get<double>(function[i - 1]),
                                std::get<double>(function[i + 1]));
            function[i + 1] = std::nan("");
            function[i - 1] = std::nan("");
            break;
          case '/':
            function[i] = divide(std::get<double>(function[i - 1]),
                                 std::get<double>(function[i + 1]));
            function[i + 1] = std::nan("");
            function[i - 1] = std::nan("");
            break;
          case '^':
            function[i] = pow(std::get<double>(function[i - 1]),
                              std::get<double>(function[i + 1]));
            function[i + 1] = std::nan("");
            function[i - 1] = std::nan("");
            break;
          default:
            throw std::logic_error("ERROR03");
            break;
        }
      }
      scanFunc();
    }
  }
  for (size_t i = 0; i < function.size(); i++) {
    if (std::holds_alternative<double>(function[i])) {
      if (std::holds_alternative<char>(function[i])) {
        if (std::get<char>(function[i]) == '(' ||
            std::get<char>(function[i]) == ')') {
          function.erase(function.begin() + i);
          i--;
        }
      }
    }
  }
  return std::get<double>(function[0]);
}

}  // namespace sgt
#endif