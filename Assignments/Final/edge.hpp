#pragma once

#include "vertex.hpp"

struct edge {
    vertex *start;
    vertex *end;
    int weight;
};