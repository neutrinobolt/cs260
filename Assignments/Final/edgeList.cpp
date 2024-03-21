#include <iostream>

#include "edgeList.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////
// Constructor and deconstructor
edgeList::edgeList() {
    this->root = nullptr;
    this->count = 0;
}

edgeList::~edgeList() {
    cout << "Deconstructing edgelist..." << endl;
    while (this->count > 0) {
        // cout << "Deleting root..." << endl;
        this->pop();
        // cout << "count:" << this->count << endl;
    }
}

////////////////////////////////////////////////////////////////
// Main functions

void edgeList::push(edge *newEdge) {
     // Point newEdge at current root
    newEdge->listNext = this->root;
    // Set root to newVert
    this->root = newEdge;
    // Add one to count
    count++;
}

void edgeList::pop() {
    // Set root to root->listNext
    edge *oldRoot = this->root;
    this->root = oldRoot->listNext;
    // delete old root
    delete oldRoot;
    // Subract one from count
    count--;
}

edge *edgeList::searchByConns(char startId, char endId) {
    // check each edge, if conns match, return 
    // cout << "Searching for id " << searchId << endl;
    edge *checkEdge = this->root;
    while (checkEdge != nullptr) {
        // cout << "checkVert: " << checkVert->id << endl;
        if ((checkEdge->start->id == startId) && (checkEdge->end->id == endId)) {
            return checkEdge;
        }
        checkEdge = checkEdge->listNext;
    }
    // If end of list is reached w/o finding vert, print error and return root
    cout << "Edge of connectors " << startId << ", ";
    cout << endId << " Not found. returning root." << endl;
    return this->root;
}

void edgeList::remove(char startId, char endId) {
    // Find edge
    edge *remEdge = this->searchByConns(startId, endId);
    cout << "Found edge" << endl;

    if (remEdge != this->root) {
        // Get previous
        cout << "Finding previous edge:" << endl;
        edge *remPrev = this->getPrevious(startId, endId); 
        cout << "remPrev: " << remPrev->start->id << remPrev->end->id << endl;
        // Set previous next to remedge next
        remPrev->listNext = remEdge->listNext;
        cout << "remPrev->listNext->id: " << remPrev->listNext->start->id << remPrev->listNext->end->id << endl;
        // delete remedge
        delete remEdge;
    }
    else {
        this->pop();
    }
    // Decrement count
    count--;
}

void edgeList::sortByWeight() {
    cout << "Sorting..." << endl;
    bool done = false;
    while (done == false) {
        done = true;
        edge *checkEdge = this->root;
        for (int i = 0; i < this->count; i++) {
            cout << "Checkedge, next: " << checkEdge->weight << checkEdge->listNext->weight << endl;
            if (checkEdge->weight > checkEdge->listNext->weight) {
                cout << "Swap required." << endl;
                this->swap(checkEdge);
                done = false;
            }
            checkEdge = checkEdge->listNext;
            cout << "One round complete." << endl;
        }
        cout << "Sort complete!" << endl;
    }
}

////////////////////////////////////////////////////////////////
// Helper functions

void edgeList::swap (edge *startEdge) {
    // First swap is root
    if ((startEdge->start->id == this->root->start->id) && (startEdge->end->id == this->root->end->id)) {
        cout << "Swapping root:" << endl;
        // Get isolated vertices
        edge *newRoot = startEdge->listNext;
        edge *newNext = startEdge;
        // Adjust new vertex pointers
        newRoot->listNext = newNext;
        newNext->listNext = startEdge->listNext->listNext;
        // Replace old vertices with new ones
        startEdge->listNext = newNext;
        startEdge = newRoot;
    }
    // First swap is not root, second isn't end
    else {
        cout << "Swapping nonroot:" << endl;
        // Get previous, start and next
        edge *preVert = this->getPrevious(startEdge->start->id, startEdge->end->id);
        edge *newStart = startEdge->listNext;
        edge *newNext = startEdge;
        // Set pointers on new vertices
        preVert->listNext = newStart;
        newStart->listNext = newNext;
        newNext->listNext = startEdge->listNext->listNext;
        // Replace old vertices with new ones
        startEdge->listNext = newNext;
        startEdge = newStart;
    }
}

edge *edgeList::getPrevious(char startId, char endId) {
    edge *checkEdge = this->root;
    while (checkEdge != nullptr) {
        if ((checkEdge->listNext->start->id == startId) && (checkEdge->listNext->end->id == endId)) {
            return checkEdge;
        }
        checkEdge = checkEdge->listNext;
    }
    cout << "ERROR, id not found." << endl;
    return this->root;
}