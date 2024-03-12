#pragma once

#include <iostream>

using std::string;

struct keyLink {
    string *key;
    keyLink *next;
    keyLink();
    ~keyLink();
};
