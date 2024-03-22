#pragma once

#include "vertList.hpp"
#include "edgeList.hpp"

class graph {
    
    public:
        vertList *vertices;
        edgeList *edges;

        graph();
        ~graph();
        
        void addVert(char vertId);
        void addEdge(char startId, char endId, int weight);
        bool pathFind (char startId, char endId);
        edgeList *minSTree();
        vertex *getVert(char searchId);
        edge *getEdge(char startId, char endId);

    private:

};
