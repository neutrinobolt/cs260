#include <iostream>

#include "binNode.hpp"
#include "binSTree.hpp"

using std::cout;
using std::endl;

int main() {
    BinSTree *testTree = new BinSTree;

    ////////////////////////////////////////////////////////////////
    // Test add function
    // add root node, check it's there
    testTree->add(20);
    cout << "testTree->root->value: " << testTree->root->value << endl;
    // add node left of root, check it's there
    testTree->add(10);
    cout << "testTree->root->left->value: " << testTree->root->left->value << endl;
    // add node right of root, check it's there
    testTree->add(30);
    cout << "testTree->root->right->value: " << testTree->root->right->value << endl;


    // Garbage Collection
    testTree->~BinSTree();

    return 0;
}
