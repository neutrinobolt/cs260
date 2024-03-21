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
    vertex *search(char searchId);
    void remove(char remId);
    void sortByDist();

    private:
    void swap(vertex *startVert);
    vertex *getPrevious(char searchId);

};