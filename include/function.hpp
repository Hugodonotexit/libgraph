#ifndef CLIBFUNCTION_H
#define CLIBFUNCTION_H
#include <string>
#include <vector>
#include <tuple>
namespace graph {

class Expression {
 private:
    struct Function {
      std::vector<std::tuple<int,char>> operators;
      std::vector<std::tuple<int,double>> numbers;
      std::vector<std::tuple<int,char>> _x;
    };
 public:
  Expression();
  void set_expression();
  void compile_expression();
  double get_answer(double x);
  std::string get_expression() const;
  ~Expression();
};

}  // namespace graph

#endif