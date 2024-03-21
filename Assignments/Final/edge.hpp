#pragma once

#include "vertex.hpp"

struct edge {
    vertex *start;
    vertex *end;
    edge *listNext;
    int weight;

    edge(vertex *start, vertex *end);
};