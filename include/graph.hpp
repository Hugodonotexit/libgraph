#ifndef CLIBGRAPH_H
#define CLIBGRAPH_H
#include "function.hpp"
#include <SDL2/SDL.h>

namespace graph
{
    class Graph
    {
    private:
        std::vector<Expression>  expressions;
        std::vector<Vectorlf> points;
    protected:
        Graph();
        ~Graph();
    };
}

#endif