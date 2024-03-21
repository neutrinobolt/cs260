#include <iostream>

#include "edge.hpp"

edge::edge(vertex *start, vertex *end, int weight) {
    this->weight = weight;
    this->end = end;
    this->start = start;
    this->listNext = nullptr;
}
