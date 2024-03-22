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
    this->count++;

}

void vertList::pop() {
    // Set root to root->listNext
    vertex *oldRoot = this->root;
    this->root = oldRoot->listNext;
    // delete old root
    delete oldRoot;
    // Subract one from count
    this->count--;
}

vertex *vertList::search(char searchId) {
    // check each vert, if equals searchVert, return 
    // cout << "Searching for id " << searchId << endl;
    vertex *checkVert = this->root;
    for (int i = 0; i < this->count; i++) {
        // cout << "checkVert: " << checkVert->id << endl;
        if (checkVert->id == searchId) {
            return checkVert;
        }
        checkVert = checkVert->listNext;
    }
    // If end of list is reached w/o finding vert, print error and return root
    // cout << "vertex of ID" << searchId << "Not found. returning root." << endl;
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
    this->count--;
}

void vertList::sortByDist() {
    // cout << "Sorting..." << endl;
    bool done = false;
    while (done == false) {
        done = true;
        vertex *checkVert = this->root;
        for (int i = 0; i < this->count; i++) {
            if ((checkVert->listNext != nullptr) && 
            (checkVert->distance > checkVert->listNext->distance)) {
                // cout << "Checkvert, next: " << checkVert->distance << checkVert->listNext->distance << endl;
                // cout << "Swap required." << endl;
                this->swap(checkVert);
                done = false;
            }
            checkVert = checkVert->listNext;
        }
        // cout << "One round complete." << endl;
    }
    // cout << "Sort complete!" << endl;
}

////////////////////////////////////////////////////////////////
// Helper functions

// Swap adjacent vertices
void vertList::swap(vertex *startVert) {
        // Copy next's info to pholder
        vertex *pHolder = new vertex(startVert->listNext->id);
        pHolder->distance = startVert->listNext->distance;
        pHolder->prev = startVert->listNext->prev;
        // put start vert info in next
        startVert->listNext->id = startVert->id;
        startVert->listNext->distance = startVert->distance;
        startVert->listNext->prev = startVert->prev;
        // Put pholder ingo in start
        startVert->id = pHolder->id;
        startVert->distance = pHolder->distance;
        startVert->prev = pHolder->prev;
        // 
        delete pHolder;
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
