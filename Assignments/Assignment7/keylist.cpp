#include <iostream>

#include "keylist.hpp"

using std::cout;
using std::endl;

keyList::keyList() {
    this->root = nullptr;
}

keyList::~keyList() {
    while (this->root != nullptr) {
        this->pop();
    }
    delete this->root;
}

// Add new key to top of stack
void keyList::push(string *key) {
    // Create new link
    keyLink *pushLink = new keyLink;
    pushLink->key = key; 

    // Point to current root
    pushLink->next = this->root;

    // Set root to new link
    this->root = pushLink;
}

// Remove top key
void keyList::pop() {
    // Get current root
    keyLink *popKey = this->root;

    // Set root to root's next
    this->root = popKey->next;

    // Destroy old root
    popKey->~keyLink();
}

// Remove input key
void keyList::remove(string *key) {
    // Make sure key is in stack
    if (this->checkKey(key) == false) {
        cout << "Error, invalid key searched." << endl;
    }
    else {
        // If key is root, just pop
        if (key == this->root->key) {
            this->pop();
        }
        else {
            // Find key pointing to key to remove
            keyLink *remPrev = this->getPrev(key);
            // Set previous's next to remKey's next
            remPrev->next = remPrev->next->next;

            // Destroy remKey
            keyLink *remKey = this->getKey(key);
            remKey->~keyLink();
        }
    }
}