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

void graph::addEdge(char startId, char endId, int weight) {
    // Find start and end vertices
    vertex *startVert = this->getVert(startId);
    vertex *endVert = this->getVert(endId);
    // Create new edge
    edge *newEdge = new edge(startVert, endVert, weight);
    // Add to edges
    this->edges->push(newEdge);
}

////////////////////////////////////////////////////////////////
// Helper functionss

vertex *graph::getVert(char searchId) {
    return this->vertices->search(searchId);
}

edge *graph::getEdge(char startId, char endId) {
    return this->edges->searchByConns(startId, endId);
}
