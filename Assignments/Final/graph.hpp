#pragma once

#include "vertList.hpp"
#include "edgeList.hpp"

class graph {
    
    public:
        int vertCount;
        vertList *vertices;
        edgeList *edges;

        graph();
        ~graph();
        
        void addVert(char vertId);
        void addEdge(vertex *startVert, vertex *endVert, int weight);
        void pathFind (vertex *startVert, vertex *endVert);
        edgeList *minSTree();

    private:
        vertex *getVert(vertex *searchVert);
        edge *getEdge(vertex *searchEdge);

};
