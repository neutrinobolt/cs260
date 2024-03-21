#include <iostream>

#include "graph.hpp"

using std::cout;
using std::endl;

int main() {
    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    // Test vertList functions
    cout << endl << "Testing vertlist" << endl << endl;
    vertList *testVList = new vertList;
    // char *A = A;
    // char *B = B;
    // char *C = C;
    // char *D = D;

    ////////////////////////////////////////////////////////////////
    // Test push
    cout << endl << "Testing push" <<endl;
    cout << "Initializing vertA:" << endl;
    vertex *vertA = new vertex('A');
    cout << "Pushing vertA:" << endl;
    testVList->push(vertA);
    cout << "testVList->root->id: " << testVList->root->id << endl;

    ////////////////////////////////////////////////////////////////
    //Test pop
    cout << endl << "Testing pop" << endl;
    testVList->pop();
    if (testVList->root == nullptr) {
        cout << "Pop successful." << endl;
    }
    else {
        cout << "Error, pop failed." << endl;
    }

    ////////////////////////////////////////////////////////////////
    // Test search
    cout << endl << "Testing search" << endl;

    // Refill list
    vertA = new vertex('A');
    vertex *vertB = new vertex('B');
    vertex *vertC = new vertex('C');
    vertex *vertD = new vertex('D');
    cout << "New vertices initialized." << endl;

    testVList->push(vertA);
    testVList->push(vertB);
    testVList->push(vertC);
    testVList->push(vertD);
    cout << "New vertices pushed." << endl;

    // Search for each vert
    vertex *searchA = testVList->search('A');
    vertex *searchB = testVList->search('B');
    vertex *searchC = testVList->search('C');
    vertex *searchD = testVList->search('D');
    cout << "New vertices found." << endl;

    // Print results
    cout << "searchA->id: " << searchA->id << endl;
    cout << "searchB->id: " << searchB->id << endl;
    cout << "searchC->id: " << searchC->id << endl;
    cout << "searchD->id: " << searchD->id << endl;

    ////////////////////////////////////////////////////////////////
    // Test remove
    cout << endl << "Testing remove" << endl;
    // remove C
    cout << "root: " << testVList->root->id << endl;
    cout << "Removing C:" << endl;
    testVList->remove('C');
    // Check where C was. Should show B
    cout << "testVList->root->listNext: " << testVList->root->listNext->id << endl;
    vertex *printVert = testVList->root; 
    cout << "list:" << endl;
    for (int i = 0; i < testVList->count; i++) {
        cout << printVert->id << ", ";
        printVert = printVert->listNext;
    }
    cout << endl;

    ////////////////////////////////////////////////////////////////
    // Test sort
    cout << endl << "testing sort:" << endl;

    // Set all distances to different values
    vertA->distance = 5;
    vertB->distance = 10;
    vertD->distance = 1;

    // Run sort
    testVList->sortByDist();

    // Print list in order. Should be D, A, B, 
    printVert = testVList->root; 
    cout << "Sorted list:" << endl;
    for (int i = 0; i < testVList->count; i++) {
        cout << printVert->id << ", ";
        printVert = printVert->listNext;
    }
    cout << endl;

    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    // Test edgeList functions

    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    // Test graph functions

    ////////////////////////////////////////////////////////////////
    // Test adding vert

     ////////////////////////////////////////////////////////////////
    //  Test adding edge

    ////////////////////////////////////////////////////////////////
    // Test dijkstra

    ////////////////////////////////////////////////////////////////
    // Test Kruskal

    ////////////////////////////////////////////////////////////////
    // Garbage collection
    cout << endl << "Cleaning..." << endl;
    testVList->~vertList();
    cout << "All clean!" << endl;


    return 0;
}
