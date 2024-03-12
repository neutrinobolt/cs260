#pragma once

#include <iostream>

using std::string;

class hTable {
    private:
        int collCheck(int index);
        
    public:
        string hashArray[10];
        // Construction and destruction
        hTable();
        ~hTable();
        // Functions to test
        int hash(string key);
        void insert (string key, string value);
        void remove (string key, string value);
        bool valCheck (string value);
};
