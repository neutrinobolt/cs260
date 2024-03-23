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
    // cout << "Setting up pathFind:" << endl;
    vertex *startVert = this->getVert(startId);
    vertex *endVert = this->getVert(endId);
    // cout << "Distances set. Creating unchecked list..." << endl;
    // Create secondary vertList
    vertList *unchecked = new vertList;
    vertex *addVert = this->vertices->root;
    while (addVert != nullptr) {
        // cout << "Adding vertex: " << addVert->id << endl;
        addVert->distance = 500;
        vertex *subVert = new vertex(addVert->id);
        unchecked->push(subVert);
        addVert = addVert->listNext;
        // cout << "Vert added." << endl;
    }
    
    unchecked->search(endId)->distance = 0;
    
    // cout << "list initialized. Beginning distance calculator..." << endl;
    // Distance calc algorithm
    edgeList *neighbors = new edgeList;
    vertex *stepVert;
    while (unchecked->count != 0) {
        // Sort list
        unchecked->sortByDist();
        // // cout << "Displaying unchecked distances..." << endl;
        // stepVert = unchecked->root;
        // while (stepVert != nullptr) {
        //     cout << stepVert->distance << ", ";
        //     stepVert = stepVert->listNext;
        // }
        // cout << endl;
        // // cout << "Displaying main distances..." << endl;
        // stepVert = this->vertices->root;
        // while (stepVert != nullptr) {
        //     cout << stepVert->distance << ", ";
        //     stepVert = stepVert->listNext;
        // }
        // cout << endl;
        // // cout << "Unchecked: " << endl;
        // stepVert = unchecked->root;
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
            
            int compDist = checKVert->distance + step->weight;
            // cout << "Compdist: " << compDist << endl;
            // Get neighbor
            if (step->start->id == checKVert->id) {
                vertex *neighbor = this->vertices->search(step->end->id);
                // cout << "neighbor: " << neighbor->id << endl;
                // cout << "neighbor->distance: " << neighbor->distance << endl;
                // If necessary, update neighbor distance
                if ((neighbor->distance > compDist) && 
                (neighbor->id == unchecked->search(neighbor->id)->id)) {
                    // cout << "Updating end neighbor distance:" << endl;
                    neighbor->distance = compDist;
                    unchecked->search(neighbor->id)->distance = compDist;
                    this->vertices->search(neighbor->id)->distance = compDist;
                    // cout << "this->vertices->search(neighbor->id): ";
                    // cout << this->vertices->search(neighbor->id)->id << endl;
                    // cout << "this->vertices->search(neighbor->id)->distance: ";
                    // cout << this->vertices->search(neighbor->id)->distance << endl;
                    this->vertices->search(neighbor->id)->prev = this->vertices->search(checKVert->id);
                    // cout << "neighbor->prev: " << neighbor->prev->id << endl;
                }
            }
            else {
                vertex *neighbor = this->vertices->search(step->start->id);
                // cout << "neighbor: " << neighbor->id << endl;
                // cout << "neighbor->distance: " << neighbor->distance << endl;
                // If necessary, update neighbor distance
                if ((neighbor->distance > compDist) && 
                (neighbor->id == unchecked->search(neighbor->id)->id)) {
                    // cout << "Updating start neighbor distance:" << endl;
                    neighbor->distance = compDist;
                    unchecked->search(neighbor->id)->distance = compDist;
                    this->vertices->search(neighbor->id)->distance = compDist;
                    // cout << "this->vertices->search(neighbor->id)->distance: ";
                    // cout << this->vertices->search(neighbor->id)->distance << endl;
                    this->vertices->search(neighbor->id)->prev = this->vertices->search(checKVert->id);
                }
            }
            // pop step
            neighbors->pop();
        }
        // pop
        unchecked->pop();
    }
    // cout << "Distance calculator finished. Determining final result..." << endl;
    // cout << startVert->distance << endl;
    // Reset all distances
    // If start distance is still 500, return false
    if (startVert->distance == 500) {
        stepVert = this->vertices->root;
    for (int i = 0; i < this->vertices->count; i++) {
        stepVert->distance = 500;
        stepVert = stepVert->listNext;
    }
        return false;
    }
    // Else return true
    else {
        stepVert = this->vertices->root;
        for (int i = 0; i < this->vertices->count; i++) {
            stepVert->distance = 500;
            stepVert = stepVert->listNext;
        }
        return true;
    }
}

edgeList *graph::minSTree() {
    // Create secondary graph, add all edges to it
    // cout << "Creating vgraph:" << endl;
    graph *vGraph = new graph;
    for (
        vertex *stepVert = this->vertices->root;
        stepVert != nullptr;
        stepVert = stepVert->listNext
    ) {
        vGraph->addVert(stepVert->id);
        // cout << "Vertex " << stepVert->id << " added." << endl;
    }
    // Create result list
    edgeList *result = new edgeList;
    // sort edge list
    this->edges->sortByWeight();
    // Check each edge. if verts dont already have a connecting path, add to results
    // cout << "Checking edges..." << endl;
    edge *stepEdge = this->edges->root;
    while (stepEdge != nullptr) {
        // cout << "StepEdge: " << stepEdge->start->id << stepEdge->end->id << endl;
        // cout << "Step next: " << stepEdge->listNext->start->id << stepEdge->listNext->end->id << endl;
        bool areConned = vGraph->pathFind(stepEdge->start->id, stepEdge->end->id);
        // cout << "areconned: " << areConned << endl;
        if (areConned == false) {
            edge *steplica = new edge(
                stepEdge->start,
                stepEdge->end,
                stepEdge->weight
            );
            vGraph->edges->push(steplica);
            result->push(steplica);
            // cout << "Edge added." << endl;
        }
        stepEdge = stepEdge->listNext;
    }
    // Return results
    return result;
}

////////////////////////////////////////////////////////////////
// Helper functionss

vertex *graph::getVert(char searchId) {
    return this->vertices->search(searchId);
}

edge *graph::getEdge(char startId, char endId) {
    return this->edges->searchByConns(startId, endId);
}
