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

bool graph::pathFind (char startId, char endId) {
    // Get start and end vertices
    cout << "Setting up pathFind:" << endl;
    vertex *startVert = this->getVert(startId);
    vertex *endVert = this->getVert(endId);
    cout << "Distances set. Creating unchecked list..." << endl;
    // Create secondary vertList
    vertList *unchecked = new vertList;
    vertex *addVert = this->vertices->root;
    while (addVert != nullptr) {
        // cout << "Adding vertex: " << addVert->id << endl;
        vertex *subVert = new vertex(addVert->id);
        unchecked->push(subVert);
        addVert = addVert->listNext;
        // cout << "Vert added." << endl;
    }
    
    unchecked->search(endId)->distance = 0;
    
    cout << "list initialized. Beginning distance calculator..." << endl;
    // Distance calc algorithm
    edgeList *neighbors = new edgeList;
    while (unchecked->count != 0) {
        // Sort list
        unchecked->sortByDist();
        // cout << "Unchecked: " << endl;
        // vertex *stepVert = unchecked->root;
        // for (int i = 0; i < unchecked->count; i++) {
        //     cout << stepVert->id << ", ";
        //     stepVert = stepVert->listNext;
        // }
        // cout << endl;
        // Get root
        vertex *checKVert = unchecked->root;
        // cout << "checkVert: " << checKVert->id << endl;
        // cout << "checkVert->distance: " << checKVert->distance << endl;
        // collect all root edges
        // cout << "Collecting edges..." << endl;
        edge *checkEdge = this->edges->root;
        for (int i = 0; i < this->edges->count; i++) {
            edge *subEdge = new edge(checkEdge->start, checkEdge->end, checkEdge->weight);
            if ((subEdge->start->id == checKVert->id) || (subEdge->end->id == checKVert->id)) {
                // cout << "Adding to neighbors: " << subEdge->start->id << subEdge->end->id << endl;
                neighbors->push(subEdge);
            }
            checkEdge = checkEdge->listNext;
        }
        // Update distances of all neighbors
        // cout << "updating neighbor distances..." << endl;
        while (neighbors->count != 0) {
            edge *step = neighbors->root;
            vertex *neighbor;
            int compDist = checKVert->distance + step->weight;
            // cout << "Compdist: " << compDist << endl;
            // Get neighbor
            if (step->start->id == checKVert->id) {
                neighbor = step->end;
                // cout << "neighbor: " << neighbor->id << endl;
                // cout << "neighbor->distance: " << neighbor->distance << endl;
                // If necessary, update neighbor distance
                if ((neighbor->distance > compDist) && 
                (neighbor->id == unchecked->search(neighbor->id)->id)) {
                    // cout << "Updating end neighbor distance:" << endl;
                    neighbor->distance = compDist;
                    unchecked->search(neighbor->id)->distance = compDist;
                    // this->vertices->search(neighbor->id)->distance = compDist;
                    // cout << "this->vertices->search(neighbor->id): ";
                    // cout << this->vertices->search(neighbor->id)->id << endl;
                    // cout << "this->vertices->search(neighbor->id)->distance: ";
                    // cout << this->vertices->search(neighbor->id)->distance << endl;
                    this->vertices->search(neighbor->id)->prev = this->vertices->search(checKVert->id);
                    // cout << "neighbor->prev: " << neighbor->prev->id << endl;
                }
            }
            else {
                neighbor = step->start;
                // cout << "neighbor: " << neighbor->id << endl;
                // cout << "neighbor->distance: " << neighbor->distance << endl;
                // If necessary, update neighbor distance
                if ((neighbor->distance > compDist) && 
                (neighbor->id == unchecked->search(neighbor->id)->id)) {
                    // cout << "Updating start neighbor distance:" << endl;
                    neighbor->distance = compDist;
                    unchecked->search(neighbor->id)->distance = compDist;
                    // this->vertices->search(neighbor->id)->distance = compDist;
                    this->vertices->search(neighbor->id)->prev = this->vertices->search(checKVert->id);
                }
            }
            // pop step
            neighbors->pop();
            // cout << "Remaining neighbors:" << endl;
            // edge *stepEdge = neighbors->root; 
            // for (int i = 0; i < neighbors->count; i++) {
            //     cout << stepEdge->start->id << stepEdge->end->id << ", ";
            //     stepEdge = stepEdge->listNext;
            // }
            // cout << endl;
        }
        // pop
        unchecked->pop();
    }
    cout << "Distance calculator finished. Determining final result..." << endl;
    // If start distance is still 500, return false
    if (startVert->distance == 500) {
        return false;
    }
    // Else return true
    else {return true;}
    cout << "Pathfind finished!" << endl;
}

////////////////////////////////////////////////////////////////
// Helper functionss

vertex *graph::getVert(char searchId) {
    return this->vertices->search(searchId);
}

edge *graph::getEdge(char startId, char endId) {
    return this->edges->searchByConns(startId, endId);
}
