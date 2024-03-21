#include <iostream>

#include "graph.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////
// Contstruction and destruction

graph::graph(){
    this->vertices = new vertList;
    this->edges = new edgeList;
}

graph::~graph() {
    delete this->vertices;
    delete this->edges;
}

////////////////////////////////////////////////////////////////
// main functions
void graph::addVert(char vertId) {
    // Create new vertex
    vertex *newVert = new vertex(vertId);
    // Add to vertices
    this->vertices->push(newVert);
}

////////////////////////////////////////////////////////////////
// Helper functionss
