#include "hash.hpp"

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

    // Insert value at hash index
    this->hashArray[hInd] = value;

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
