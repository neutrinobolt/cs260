#include "hash.hpp"

////////////////////////////////////////////////////////////////
// Define functions from hash.hpp
hTable::hTable() {
    // Create all indices with empty strings
    for (int index = 0; index < 10; index++) {
        this->hashArray[index] = "";
    }

}

hTable::~hTable() {

}

int hTable::hash(string key) {

}

void hTable::insert(string key, string value) {

}

bool hTable::lookup(string value) {

}
