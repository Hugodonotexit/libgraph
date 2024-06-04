#include "../sdlgraphic.hpp"

int main() {
    sgt::SDLG graph;
    sgt::Func func("sin(x)+100");
    graph.pushFunc(func);
    graph.setCurve(0);
    graph.startLoop();
    return 0;
}