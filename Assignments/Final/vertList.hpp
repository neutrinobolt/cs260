#pragma once

#include "vertex.hpp"

class vertList {
    public:
    vertex *root;
    int count;

    vertList();
    ~vertList();

    void push(vertex *newVert);
    void pop();
    void search(vertex *searchVert);
    void remove(vertex *remvert);
    void sort();

    private:
    void swap(vertex *startVert);

};