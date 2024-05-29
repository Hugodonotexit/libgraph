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
  std::vector<std::pair<size_t,size_t>> bracket;
  std::vector<Vectorlf> point;
  void checkFunc();
  void locateBracket();
  void pushFunc();
  
 public:
  Func();
  Func(std::string _function);
  void setFunc(std::string _function);
  std::string getFunc() const;
  void get_y(double x);
  void setCurve();
  void setCurve(sgt::Colour colour);
  ~Func();
};

Func::Func(){};
Func::Func(std::string _function) : _function(_function){};
void Func::setFunc(std::string _function) {
  this->_function = _function;
  try {
    checkFunc();
  } catch (const std::logic_error& e) {
    std::cerr << "Undefined function!!! " << e.what() << std::endl;
    _function = "NULL";
    function.erase(function.begin(),function.end());
    return;
  }
  pushFunc();
  try {
    locateBracket();;
  } catch (const std::logic_error& e) {
    std::cerr << "Undefined function!!! " << e.what() << std::endl;
    _function = "NULL";
    function.erase(function.begin(),function.end());
    return;
  }
};
std::string Func::getFunc() const { return _function; };
Func::~Func(){};

void Func::checkFunc() {
  if (_function[1] == '/' || _function[1] == '*' ||
      _function[1] == '^' || _function[1] == '!') {
    throw std::logic_error("ERROR00");
    return;
  }
  if (_function[_function.size()-1] == '/' || _function[_function.size()-1] == '*' || _function[_function.size()-1] == '+' ||
      _function[_function.size()-1] == '^' || _function[_function.size()-1] == '!' || _function[_function.size()-1] == '-') {
    throw std::logic_error("ERROR00");
    return;
  }

  for (size_t i = 0; i < _function.size(); i++) {
    if (_function[i] == '(' && (_function[i+1] == '/' || _function[i+1] == '*' ||
      _function[i+1] == '^' || _function[i+1] == '!')) {
    throw std::logic_error("ERROR00");
    return;
  }
    switch (_function[i]) {
      case '.':
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '+':
      case '-':
      case '*':
      case '^':
      case '!':
      case 'x':
      case 'e':
      case 'a':
      case 'h':
      case 'i':
      case 'l':
      case 'n':
      case 'o':
      case 'p':
      case 's':
      case 't':
      case '|':
      case '(':
      case ')':
        break;
      default:
        throw std::logic_error("ERROR00");
        return;
        break;
    }
  }
};
void Func::locateBracket() {
  std::vector<size_t> openBracket, closeBracket;
  for (size_t i = 0; i < function.size(); i++) {
    if (std::holds_alternative<char>(function[i])) {
      if (std::get<char>(function[i]) == '(') {
        openBracket.push_back(i);
      } else if (std::get<char>(function[i]) == ')') {
        closeBracket.push_back(i);
      }
    }
  }
  if (openBracket.size() != closeBracket.size())
  {
    throw std::logic_error("ERROR00");
    return;
  }
  for (size_t i = openBracket.size() - 1; i >= 0; i--)
  {
    if (openBracket[i] >= closeBracket[i])
    {
      throw std::logic_error("ERROR00");
      return;
    }   
  }
  for (size_t i = 0; i < openBracket.size() - 1; i++)
  {
    for (size_t j = closeBracket.size(); j >= 0; j--)
    {
       bracket.push_back(std::make_pair(openBracket[i],closeBracket[j]));
    }   
  }
}
  void Func::pushFunc() {
    bool isNum = false;
    size_t numCharStart;
    for (size_t i = 0; i < _function.size(); i++) {
      if ((std::isdigit(_function[i]) || _function[i] == '.') && !isNum)
      {
        isNum = true;
        numCharStart = i;
        continue;;
      } else if (!std::isdigit(_function[i]) && isNum){
        isNum = false;
        double num = std::stod(_function.substr(numCharStart, i - 1));
        function.push_back(num);
        continue;
      } else if (std::isdigit(_function[i]) && isNum) {continue;}
      function.push_back(_function[i]);
    }
  };

  void Func::get_y(double x) {
    std::vector<double> tempNum;
    std::vector<char> tempOp;
    size_t doneIndex = 0, bracketIndex = bracket.size() - 1;
    for (size_t i = 0; i < function.size(); i++)
      {
        if (std::holds_alternative<char>(function[i]))
        {
          if (std::get<char>(function[i]) == 'x')
          {
            function[i] = x;
          }
          
        }
        
      }
    while (doneIndex != function.size())
    {
      for (size_t i = bracket[bracketIndex].first; i < bracket[bracketIndex].second; i++)
      {
        if (std::holds_alternative<char>(function[i])){

        } else {

        }
      }
      
    }
    
    
  }
}  // namespace sgt
#endif