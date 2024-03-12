#pragma once

#include <iostream>

#include "keylink.hpp"

class keyList {
    private:
    bool checkKey(string *key);
    keyLink *getKey(string *key);
    keyLink *getPrev(string *key);

    public:
        keyLink *root;

        keyList();
        ~keyList();
        void push(string *key);
        void pop();
        void remove(string *key);
        
};