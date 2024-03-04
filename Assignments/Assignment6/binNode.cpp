#include <iostream>

#include "binNode.hpp"

using std::cout;
using std::endl;

    BinNode::BinNode() {
        value = 0;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    };