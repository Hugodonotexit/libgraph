#include "../function.hpp"
#include <iostream>

using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    sgt::Func func;
    string y[20];
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
    y[11] = "5^(x*2+1)-x/(x+1)";
    y[12] = "x^3-x^2+x-1+e^(-x)";
    y[13] = "(ln(x)/ln(10))^2+1/(x^2)";
    y[14] = "(e^x/(1+e^x))-(x^3/(3+cos(x)))";
    y[15] = "2^x-11/12";
    y[16] = "2^x+10";
    y[17] = "5^x-5";
    y[18] = "2^x+11/12";
    y[19] = "2^x/pi";
    for (int i = 0; i < 20; i++)
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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "The function took " << duration.count() << " seconds to run." << std::endl;
    return 0;
}