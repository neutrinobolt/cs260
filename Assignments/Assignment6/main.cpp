#include <iostream>

#include "binNode.hpp"
#include "binSTree.hpp"

using std::cout;
using std::endl;

int main() {
    BinSTree *testTree = new BinSTree;

    ////////////////////////////////////////////////////////////////
    // Test add function
    cout << endl << "Add function testing:" << endl;
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
    cout << endl << "Search function testing:" << endl;
    // Test true result. Should return 1
    bool trueRes = testTree->search(5);
    cout << "trueRes: " << trueRes << endl;
    // Test false result. Should return 0
    bool falseRes = testTree->search(24);
    cout << "falseRes: " << falseRes << endl;

    ////////////////////////////////////////////////////////////////
    // Test ioTraversal function
    cout << endl << "io traversal testing:" << endl;
    // Should print "3,5,8,10,13,15,18,20,23,25,28,30,33,35,38,"
    cout << "testTree->ioTraversal(): ";
    testTree->ioTraversal();

    ////////////////////////////////////////////////////////////////
    // Test Remove function
    cout << endl << "Remove testing:" << endl;
    // Test error catching: input invalid value
    testTree->remove(14);
    // testTree->ioTraversal();
    // Test no children
    testTree->remove(3);
    // testTree->ioTraversal();

    testTree->remove(38);
    // testTree->ioTraversal();

    // Test one child

    // Child on left
    testTree->remove(35);
    // testTree->ioTraversal();

    // Child on right
    testTree->remove(5);
    // testTree->ioTraversal();

    // 2 children
    // Right child is successor
    testTree->remove(30);
    // testTree->ioTraversal();
    // Right child is not successor
    testTree->remove(10);
    // testTree->ioTraversal();

    // Remove root
    // cout << "Attempting to delete root:" << endl;
    // testTree->remove(20);
    
    // Garbage Collection
    cout << endl << "Garbage collection" << endl;
    testTree->~BinSTree();

    return 0;
}
