#include <iostream>

#include "vertex.hpp"

using std::cout;
using std::endl;

vertex::vertex(char id) {
    this->degree = 0;
    this->distance = 500;
    this->id = id;
    this->prev = nullptr;
    this->listNext = nullptr;
}
