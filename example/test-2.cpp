#include "../sdlgraphic.hpp"
#include <iostream>

int main() {
    sgt::SDLG graph;
    sgt::Func func("10*sin(x)");
    graph.pushFunc(func);
    sgt::Vectorlf e(8,-8);
    sgt::Vectorlf f(-8,8);
    graph.setLine(e,f,sgt::Colour::Red());

    while (graph.getStatus())
    {
        graph.run();
    }

    return 0;
}