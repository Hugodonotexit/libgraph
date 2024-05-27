#include "../include/function.hpp"

using namespace graph;

int main() {
    Expression exp("x*x");
    std::cout << exp.get_expression() << std::endl;
}