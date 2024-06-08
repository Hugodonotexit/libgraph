#include "../function.hpp"
#include <iostream>

using namespace std;

int main() {
    sgt::Func func;
    string y[15];
    y[0] = "sin(x)";
    y[1] = "cos(x)";
    y[2] = "tan(x)";
    y[3] = "ln(x)/ln(10)"; // Logarithm base 10
    y[4] = "e^x"; // Exponential function
    y[5] = "x^2";
    y[6] = "x^(1/2)"; // Square root
    y[7] = "1/x";
    y[8] = "x^3+x^2+x+1";
    y[9] = "e^x/(1+e^x)"; // Sigmoid function
    y[10] = "sin(x)*cos(x)+tan(x)/x";
    y[11] = "e^(x^2+1)-x/(x+1)";
    y[12] = "x^3-x^2+x-1+e^(-x)";
    y[13] = "(ln(x)/ln(10))^2+1/(x^2)";
    y[14] = "e^x/(1+e^x)-x^3/(3+cos(x))";
    for (int i = 0; i < 15; i++)
    {
        try
        {
            func.setFunc(y[i]);
            cout << func.getFunc() << endl;
            cout << "f(" << i << ")=" << func.get_y(i) << endl;
            cout << "--------------------------------------" << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
        
        
    }
    return 0;
}