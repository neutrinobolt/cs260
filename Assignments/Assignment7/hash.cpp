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
    for (int step; step < key.length(); step++) {
        result += int(key[step]);
    }
    return result % 10;

}

void hTable::insert(string key, string value) {

}

bool hTable::lookup(string value) {
    bool result = false; // Change later
    return result;

}
