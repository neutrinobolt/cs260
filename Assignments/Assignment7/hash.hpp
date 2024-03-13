#pragma once

#include <iostream>

#include "keylist.hpp"

using std::string;

class hTable {
    private:
        keyList *keys;
        int collCheck(int index);
        int findInd(int startInd, string value);
        
    public:
        string hashArray[10];
        int *count;
        // Construction and destruction
        hTable();
        ~hTable();
        // Functions to test
        int hash(string key);
        void insert (string key, string value);
        void remove (string key, string value);
        bool valCheck (string value);
};
