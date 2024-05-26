#ifndef CLIBGRAPH_H
#define CLIBGRAPH_H

namespace graph
{
    struct Vectorlf
    {
        double x;
        double y;

        Vectorlf(double initX, double initY) : x(initX), y(initY) {}
    };

    class Graph
    {
    private:
        /* data */
    public:
        Graph(/* args */);
        ~Graph();
    };
}

#endif