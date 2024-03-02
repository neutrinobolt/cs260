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

    ////////////////////////////////////////////////////////////////
    // Test search function
    // Test true result. Should return 1
    bool trueRes = testTree->search(10);
    cout << "trueRes: " << trueRes << endl;
    // Test false result. Should return 0
    bool falseRes = testTree->search(25);
    cout << "falseRes: " << falseRes << endl;
    // Garbage Collection
    testTree->~BinSTree();

    return 0;
}
