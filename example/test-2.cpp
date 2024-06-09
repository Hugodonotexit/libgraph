#include "../sdlgraphic.hpp"

int main() {
    sgt::SDLG graph;
    //sgt::Func func("10*sin(x)+100");
    //graph.pushFunc(func);
    sgt::Vectorlf a(-100,-100);
    sgt::Vectorlf b(100,100);
    graph.setLine(a,b,sgt::Colour::Green());
    sgt::Vectorlf c(100,100);
    sgt::Vectorlf d(-100,-100);
    graph.setLine(c,d,sgt::Colour::Blue());
    sgt::Vectorlf e(100,5);
    sgt::Vectorlf f(-100,5);
    graph.setLine(e,f,sgt::Colour::Yellow());
    graph.startLoop();
    return 0;
}