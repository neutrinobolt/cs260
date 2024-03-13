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
    hashArray = new string[size];
    // Create key and val list
    this->keys = new keyList;
    this->vals = new keyList;
    // Start count at 0
    this->count = 0;
}

hTable::~hTable() {
    cout << "Deleting keys:" << endl;
    this->keys->~keyList();
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
    int hInd = this->hash(key);

    // Check for collisions
    hInd = collCheck(hInd);

    // Insert value at hash index
    this->hashArray[hInd] = value;

    // Add key to key list
    string *keyPoint = &key;
    this->keys->push(keyPoint);
    // cout << "this->keys->root: " << *this->keys->root->key << endl; //debug

    // Add val to val list
    string *valPoint = &value;
    this->vals->push(valPoint);

    // Count +1
    count++;

    // Check for resize, resize when half of space is full
    if (count == hashArray->length() / 2) {
        this->resize();
    }
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
        this->keys->pull(valPoint);

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
    // Get current size, return double
    int new_size = this->hashArray->length() * 2;

    // Create new hasharray
    string *newArr = new string[new_size];

    // For key and associated value, add to new array

    // Set new array to current

    // Delete old array
};
