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
    cout << "testTree->root: " << testTree->root->value << endl;

    // Add layer 3
    testTree->add(5);
    testTree->add(15);
    testTree->add(25);
    testTree->add(35);

    // add layer 4
    testTree->add(3);
    testTree->add(8);
    testTree->add(13);
    testTree->add(18);
    testTree->add(23);
    testTree->add(28);
    testTree->add(33);
    testTree->add(38);

    ////////////////////////////////////////////////////////////////
    // Test search function
    // Test true result. Should return 1
    bool trueRes = testTree->search(5);
    cout << "trueRes: " << trueRes << endl;
    // Test false result. Should return 0
    bool falseRes = testTree->search(24);
    cout << "falseRes: " << falseRes << endl;

    ////////////////////////////////////////////////////////////////
    // Test ioTraversal function
    // Should print "10, 20, 30, "
    cout << "testTree->ioTraversal(): ";
    testTree->ioTraversal();

    // Garbage Collection
    testTree->~BinSTree();

    return 0;
}
