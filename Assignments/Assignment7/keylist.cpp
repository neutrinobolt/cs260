#include <iostream>

#include "keylist.hpp"

using std::cout;
using std::endl;

keyList::keyList() {
    this->root = nullptr;
    this->count = 0;
}

keyList::~keyList() {
    while (this->count > 0) {
        // cout << "Count: " << this->count << endl;
        this->pop();
        // cout << "Popped." << endl;
        cout << "Count: " << this->count << endl;
    }
    cout << "All keys popped." << endl;
    // delete this->root;
    cout << "list deleted." << endl;
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

    count++;
}

// Remove top key
void keyList::pop() {
    // Get current root
    keyLink *popKey = this->root;

    // Set root to root's next
    this->root = popKey->next;

    // Destroy old root
    delete popKey;

    count--;
}

// Remove input key
void keyList::pull(string *key) {
    // Make sure key is in stack
    // cout << "Pulling key " << *key << endl;
    if (this->checkKey(*key) == false) {
        cout << "Error, invalid key searched." << endl;
    }
    else {
        // cout << "Usable key found" << endl; // debug
        // If key is root, just pop
        if (*key == *this->root->key) {
            // cout << "Removing root:" << endl;
            this->pop();
        }
        else {
            // Find key pointing to key to remove
            // cout << "Removing nonroot:" << endl;
            keyLink *remPrev = this->getPrev(key);
            // cout << "remPrev: " << *remPrev->key << endl; // debug
            // Isolate remKey
            keyLink *remKey = this->getKey(key);
            // cout << "remKey: " << *remKey->key << endl; // debug
            // Set previous's next to remKey's next
            remPrev->next = remKey->next;
            // cout << "Key pulled." << endl;
            // Destroy remKey
             delete remKey;
            // cout << "remKey deleted." << endl;
            
            count--;
        }
    }
}

// Return item at given location, starting at root = 0
keyLink *keyList::findByInd(int ind) {
    int count = 0;
    keyLink *result = nullptr;
    keyLink *step = this->root;
    while (step != nullptr) {
        if (count == ind) {
            result = step;
            break;
        }
        step = step->next;
    }
    return result;
}

////////////////////////////////////////////////////////////////
// Private functions

// Check if input key is in stack.
bool keyList::checkKey(string key) {
    // cout << "Checking for key: " << key << endl;
    bool result = false;
    keyLink *step = this->root;
    // Check each key
    while (step != nullptr) {
        // cout << "Step: " << step->key << endl;
        if (*step->key == key) {
            // cout << "Key found!" << endl;
            return true;
        }
        step = step->next;
    }
    cout << "Key not found..." << endl;
    return result;
}

// Return link of input key. Only run if checkKey(key) returns true!
keyLink *keyList::getKey(string *key) {
    keyLink *step = this->root;
    keyLink *result = step;
    while (step != nullptr) {
        if (*step->key == *key) {
            return step;
        }
        else {
            step = step->next;
        }
    }
    cout << "Something went wrong." << endl; 
    return result;
};

// Return link poining to link of input key. Only run if checkKey(key) returns true!
// Also only works when key is not root.
keyLink *keyList::getPrev(string *key) {
    // cout << "Retrieving key to " << *key << endl;
    keyLink *step = this->root;
    keyLink *result = step;
    while (step != nullptr) {
        // cout << "Checking key " << *step->key << endl;
        if (*step->next->key == *key) {
            // cout << "returning " << *step->next->key << endl;
            return step->next;
        }
        step = step->next;
    }
    cout << "Something went wrong." << endl; 
    return result;
};
