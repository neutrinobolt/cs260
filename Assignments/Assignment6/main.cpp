#include <iostream>

#include "binNode.hpp"
#include "binSTree.hpp"

using std::cout;
using std::endl;

int main() {
    BinSTree *testTree = new BinSTree;

    // Garbage Collection
    testTree->~BinSTree();

    return 0;
}
