#include <iostream>

#include "hash.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////
// Define functions from hash.hpp
hTable::hTable(int size) {
    // Create all indices with empty strings
    // for (int ind = 0; ind < 10; ind++) {
    //     this->hashArray[ind] = "";
    // }
    hashArray = new string[this->size];
    // Create key and val list
    this->keys = new keyList;
    this->vals = new keyList;
    // Start count at 0
    this->count = 0;
    this->size = size;
}

hTable::~hTable() {
    // cout << "Deleting keys:" << endl;
    this->keys->~keyList();
    this->vals->~keyList();
    this->hashArray->~basic_string();
}

int hTable::hash(string key) {
    int result = 0; 
    // Add ascii value of each character together, return result % table size
    for (int step = 0; step < key.length(); step++) {
        result += int(key[step]);
    }
    return result % 10;

}

void hTable::insert(string key, string value) {
    // Hash key
    cout << "Calculating ind for key: " << key << endl;
    int hInd = this->hash(key);

    // Check for collisions
    cout << "Checking for collisions..." << endl;
    hInd = collCheck(hInd);

    // Insert value at hash index
    cout << "Inserting..." << endl;
    this->hashArray[hInd] = value;

    // Add key to key list
    cout << "Updating keylist..." << endl;
    string *keyPoint = &key;
    this->keys->push(keyPoint);
    // cout << "this->keys->root: " << *this->keys->root->key << endl; //debug

    // Add val to val list
    cout << "Updating vallist..." << endl;
    string *valPoint = &value;
    this->vals->push(valPoint);

    // Count +1
    count++;

    // Check for resize, resize when half of space is full
    // cout << "Count updated. Checking for resize..." << endl;
    // cout << this->count << ", " << this->size << endl;
    // if (this->count == this->size / 2) {
    //     this->resize();
    // }
}

void hTable::remove(string key, string value) {
    // If value not present:
    if (this->valCheck(value) == false) {
        cout << "ERROR, input value not in table." << endl;
    }
    else {
        // Find index to remove
        int remInd = this->findInd(hash(key), value);
        // cout << "value found at index " << remInd << endl;

        // Replace index with ""
        this->hashArray[remInd] = "";

        // Remove key from keylist
        string *keyPoint = &key;
        // cout << "Preparing to pull key:" << endl;
        this->keys->pull(keyPoint);

        // Remove val from vals
        string *valPoint = &value;
        this->vals->pull(valPoint);

        // Count -1
        cout << "Value of key " << key << " Successfully removed." << endl;
        count--;
    }
}

bool hTable::valCheck(string value) {
    bool result = false;
    // Pass through all indices. If index == value, change result to true
    for(int index = 0; index < 10; index++) {
        if (this->hashArray[index] == value) {
            result = true;
        }
    }
    return result;

}

////////////////////////////////////////////////////////////////
// Private function declarations

int hTable::collCheck(int index) {
    // If index is open, return index
    int result = index;
    if (this->hashArray[index] != "") {
        // cout << "Collision detected!" << endl;
        result = collCheck(index + 1);
    }
    return result;
}
// Return index at which value is located
int hTable::findInd(int startInd, string value) {
    int result = startInd;
    // Check if result holds value
    if (this->hashArray[result] != value) {
        result = findInd(result + 1, value);
    }
    return result;
}

void hTable::resize() {
    cout << "Resizing table:" << endl;
    // Get current size, return double
    int newSize = this->size * 2;

    // Create new hasharray of doubled size
    cout << "Replacing old table with new one:" << endl;
    string *newArr = new string[newSize];
    string *oldArr = this->hashArray;
    this->size = newSize;
    // Set new array to current
    this->hashArray = newArr;
    cout << "Array size: " << this->hashArray->length() << endl;

    // Delete old array
    oldArr->~basic_string();

    // Create new key and val lists to add to
    keyList *oldKeys = this->keys;
    keyList *oldVals = this->vals;
    this->keys = new keyList;
    this->vals = new keyList;

    // For key and associated value, add to new array
    this->count = 0;
    cout << "Reinserting values..." << endl;
    for (int i = 0; i <= oldKeys->count; i++) {
        // Get key at list index i
        cout << "Iteration: " << i << endl;
        cout << "Collecting val and key: " << *oldKeys->root->key << endl;
        keyLink *inKey = oldKeys->root;
        // cout << "Next key: " << *oldKeys->findByInd(i)->next->key << endl;

        // Get value at list index i
        keyLink *inVal = oldVals->root;
        cout << "Inserting value of key: " << *inKey->key << endl;

        oldKeys->pop();
        oldVals->pop();
        cout << "Vals popped" << endl;
        // Place key and value to new table
        this->insert(*inKey->key, *inVal->key);
        cout << "Value inserted." << endl;
    }
    // Destroy key/val lists
    oldKeys->~keyList();
    oldVals->~keyList();

    
    cout << "Table resizing complete." << endl;

};
