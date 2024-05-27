#ifndef CLIBFUNCTION_H
#define CLIBFUNCTION_H
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

namespace graph {

struct Vectorlf
    {
        double x;
        double y;
        Vectorlf(double initX, double initY) : x(initX), y(initY) {}
    };

class Expression {
 private:
    struct Function {
      std::string strFunction;
      std::vector<std::tuple<int,char>> operators;
      std::vector<std::tuple<int,double>> numbers;
      std::vector<std::tuple<int,char>> _x;
    };

    Function function;
    bool checkPolyCharNum(char &character);
    bool checkPolyCharOperators(std::string &string);
 public:
  Expression();
  Expression(std::string strFunction);
  void set_expression(std::string strFunction);
  void compile_expression();
  double get_answer(double x);
  std::string get_expression() const;
  ~Expression();
};

}  // namespace graph

#endif