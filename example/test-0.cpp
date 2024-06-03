#include "../function.hpp"
#include <iostream>

using namespace std;

int main() {
    string y;
    double x;
    cout << "y=";
    cin >> y;
    sgt::Func func(y);
    func.printCompiled();
    cout << "x=";
    cin >> x;
    printf("%.10lf\n", func.get_y(x));
}