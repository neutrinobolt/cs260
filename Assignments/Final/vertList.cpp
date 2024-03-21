#include <iostream>

#include "vertList.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////
// Constructor and deconstructor
vertList::vertList() {
    this->root = nullptr;
    this->count = 0;
}

vertList::~vertList() {
    cout << "Deconstructing vertlist..." << endl;
    while (this->count > 0) {
        // cout << "Deleting root..." << endl;
        this->pop();
        // cout << "count:" << this->count << endl;
    }
}
////////////////////////////////////////////////////////////////
// Main functions
void vertList::push(vertex *newVert) {
    // Point newVert at current root
    newVert->listNext = this->root;
    // Set root to newVert
    this->root = newVert;
    // Add one to count
    count++;

}

void vertList::pop() {
    // Set root to root->listNext
    vertex *oldRoot = this->root;
    this->root = oldRoot->listNext;
    // delete old root
    delete oldRoot;
    // Subract one from count
    count--;
}

vertex *vertList::search(char searchId) {
    // check each vert, if equals searchVert, return 
    // cout << "Searching for id " << searchId << endl;
    vertex *checkVert = this->root;
    while (checkVert != nullptr) {
        // cout << "checkVert: " << checkVert->id << endl;
        if (checkVert->id == searchId) {
            return checkVert;
        }
        checkVert = checkVert->listNext;
    }
    // If end of list is reached w/o finding vert, print error and return root
    cout << "vertex of ID" << searchId << "Not found. returning root." << endl;
    return this->root;
}

void vertList::remove(char remId) {
    // Find vertex
    vertex *remVert = this->search(remId);
    cout << "Found vertex " << remVert->id << endl;

    if (remVert != this->root) {
        // Get previous
        cout << "Finding previous vertex:" << endl;
        vertex *remPrev = this->getPrevious(remId); 
        cout << "remPrev: " << remPrev->id << endl;
        // Set previous next to remvert next
        remPrev->listNext = remVert->listNext;
        cout << "remPrev->listNext->id: " << remPrev->listNext->id << endl;
        // delete remVert
        delete remVert;
    }
    else {
        this->pop();
    }
    // Decrement count
    count--;
}

void vertList::sortByDist() {
    cout << "Sorting..." << endl;
    bool done = false;
    while (done == false) {
        done = true;
        vertex *checkVert = this->root;
        for (int i = 0; i < this->count; i++) {
            cout << "Checkvert, next: " << checkVert->distance << checkVert->listNext->distance << endl;
            if (checkVert->distance > checkVert->listNext->distance) {
                cout << "Swap required." << endl;
                this->swap(checkVert);
                done = false;
            }
            checkVert = checkVert->listNext;
            cout << "One round complete." << endl;
        }
        cout << "Sort complete!" << endl;
    }
}

////////////////////////////////////////////////////////////////
// Helper functions

// Swap adjacent vertices
void vertList::swap(vertex *startVert) {
    // First swap is root
    if (startVert->id == this->root->id) {
        cout << "Swapping root:" << endl;
        // Get isolated vertices
        vertex *newRoot = startVert->listNext;
        vertex *newNext = startVert;
        // Adjust new vertex pointers
        newRoot->listNext = newNext;
        newNext->listNext = startVert->listNext->listNext;
        // Replace old vertices with new ones
        startVert->listNext = newNext;
        startVert = newRoot;
    }
    // First swap is not root, second isn't end
    else {
        cout << "Swapping nonroot:" << endl;
        // Get previous, start and next
        vertex *preVert = this->getPrevious(startVert->id);
        vertex *newStart = startVert->listNext;
        vertex *newNext = startVert;
        // Set pointers on new vertices
        preVert->listNext = newStart;
        newStart->listNext = newNext;
        newNext->listNext = startVert->listNext->listNext;
        // Replace old vertices with new ones
        startVert->listNext = newNext;
        startVert = newStart;
    }
}

vertex *vertList::getPrevious(char searchId) {
    vertex *checkVert = this->root;
    while (checkVert != nullptr) {
        if (checkVert->listNext->id == searchId) {
            return checkVert;
        }
        checkVert = checkVert->listNext;
    }
    cout << "ERROR, id not found." << endl;
    return this->root;
}
