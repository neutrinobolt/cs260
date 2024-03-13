#include "keylink.hpp"

#include <iostream>

using std::cout;
using std::endl;

keyLink::keyLink() {
    this->key = nullptr;
    this->next = nullptr;
}

// keyLink:: ~keyLink() {
//     delete this->key;
//     delete this->next;
// }