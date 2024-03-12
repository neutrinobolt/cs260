#include "keylink.hpp"

keyLink::keyLink() {
    this->key = nullptr;
    this->next = nullptr;
}

keyLink::~keyLink() {
    delete this->key;
    delete this->next;
}