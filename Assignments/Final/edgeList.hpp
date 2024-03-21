#pragma once

#include "edge.hpp"

class edgeList {
    public:
    edge *root;
    int count;

    edgeList();
    ~edgeList();

    void push(edge *newEdge);
    void pop();
    edge *searchByConns(char startId, char endId);
    void remove(char startId, char endId);
    void sortByWeight();

    private:
    void swap (edge *startEdge);
    edge *getPrevious(char startId, char endId);

};
