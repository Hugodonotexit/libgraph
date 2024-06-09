#include "../sdlgraphic.hpp"

int main() {
    sgt::SDLG graph;
    sgt::Func func("10*sin(x)");
    graph.pushFunc(func);
    sgt::Func fun("x^3+x^2+x+1");
    graph.pushFunc(fun);
    sgt::Vectorlf a(-500,-500);
    sgt::Vectorlf b(500,500);
    graph.setLine(a,b,sgt::Colour::Green());
    sgt::Vectorlf c(100,100);
    sgt::Vectorlf d(-100,-100);
    graph.setLine(c,d,sgt::Colour::Blue());
    sgt::Vectorlf e(300,5);
    sgt::Vectorlf f(-300,5);
    graph.setLine(e,f,sgt::Colour::Yellow());

    graph.startLoop();
    return 0;
}