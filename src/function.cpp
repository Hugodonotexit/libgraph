#include "../include/function.hpp"

using namespace graph;

Expression::Expression() {}
Expression::Expression(std::string strFunction) {
  this->function.strFunction = strFunction;
}
void Expression::set_expression(std::string strFunction) {
  this->function.strFunction = strFunction;
}
size_t j;
std::vector<char> numChar;
bool isNum;
void Expression::compile_expression() {
  int length = this->function.strFunction.length();
  if (length <= 0) {
    std::cerr << "Undefined function! ERR0" << std::endl;
    return;
  }
  for (size_t i = 0; i < length; i++) {
    switch (this->function.strFunction[i]) {
      case 'e':
        this->function.numbers.push_back(std::tuple(i,2.7182818284590452));
        break;;
      case 's':
      case 'l':
      case 'p':
      
      case '=':
        std::cerr << "Equal sign not supoorted! ERR1_0" << std::endl;
        return;
        break;
      case ' ':
        std::cerr << "Space not supoorted! ERR1_1" << std::endl;
        return;
        break;
      case '^':
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
      case ')':
      if (i == 0 && this->function.strFunction[i] != '-' && this->function.strFunction[i] != '(')
      {
        std::cerr << "Can not start with operator! ERR1_2" << std::endl;
        return;
      }
      
        this->function.operators.push_back(
            std::tuple(i, this->function.strFunction[i]));
        break;
    case 'x':
        this->function._x.push_back(
            std::tuple(i,this->function.strFunction[i]));
      default:
      if (std::isdigit(this->function.strFunction[i]))
      {
        j = i;
        numChar.clear();
        do {
          isNum = this->checkPolyCharNum(this->function.strFunction[++j]);
        } while (isNum);
        for (size_t k = i; k < j; k++)
        {
            numChar.push_back(this->function.strFunction[k]);
        }
        std::string string = std::string();
        for (size_t m = 0; m < numChar.size(); m++)
        {
            string += numChar[m];
        }
        double value =  std::stod(string);
        this->function.numbers.push_back(std::tuple(i,value));
        i = j;
      } else {
        std::cerr << "Undefined expression! ERR1_3" << std::endl;
        return;
        break;
      } 
    }
  }
}

bool Expression::checkPolyCharNum(char &character) {
  switch (character) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
    case '.':
      return true;
      break;
    default:
      std::cerr << "Undefined expression! ERR1" << std::endl;
      return false;
      break;
  }
  return false;
}

bool Expression::checkPolyCharOperators(std::string &string) {
    
}

double Expression::get_answer(double x) {
    double y = 0, temp = 0;
    size_t numLen = this->function.numbers.size();
    size_t numX = this->function._x.size();
    size_t numOpe = this->function.operators.size();
    size_t lenght = numLen + numX + numOpe;
    
    for (int i = 0; i < lenght; i++)
    {
        for (size_t j = 0; j < numLen; j++)
        {
            if (std::get<0>(this->function.numbers[j]) == i) {
                
                continue;
            }
        }
        for (size_t j = 0; j < numX; i++)
        {
             if (std::get<0>(this->function._x[j]) == i) {
                
                continue;
            }
        }
        for (size_t j = 0; j < numOpe; i++)
        {
            if (std::get<0>(this->function.operators[j]) == i) {
                
                continue;
            }
        }
    }   
    return y;
}
std::string Expression::get_expression() const {
  return this->function.strFunction;
}
Expression::~Expression(){};