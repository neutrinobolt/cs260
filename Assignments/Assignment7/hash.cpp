#include <iostream>

#include "hash.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////
// Define functions from hash.hpp
hTable::hTable() {
    // Create all indices with empty strings
    for (int ind = 0; ind < 10; ind++) {
        this->hashArray[ind] = "";
    }

}

hTable::~hTable() {

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

}

void hTable::remove(string key, string value) {
    // Find index to remove
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
        cout << "Collision detected!" << endl;
        result = collCheck(index + 1);
    }
    return result;
}
