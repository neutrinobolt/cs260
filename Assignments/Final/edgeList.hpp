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
    void search(edge *searchEdge);
    void remove(edge *remEdge);
    void sort();

    private:
    void swap (edge *startEdge);

};
