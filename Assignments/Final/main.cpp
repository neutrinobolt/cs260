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
    // Garbage collection
    cout << endl << "Cleaning..." << endl;
    testVList->~vertList();
    cout << "All clean!" << endl;

    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    // Test edgeList functions
    cout << endl << endl << "Testing edgelist" <<  endl;
    edgeList *testElist = new edgeList;

    ////////////////////////////////////////////////////////////////
    // Test push function
    cout << endl << "Testing push" << endl;
    // Reestablish vertices
    vertA = new vertex('A');
    vertB = new vertex('B');
    vertC = new vertex('C');
    vertD = new vertex('D');
    // Create new edge
    edge *edgeAB = new edge(vertA, vertB, 5);
    // Add edge
    testElist->push(edgeAB);
    // Print root
    cout << "testElist->root: " << testElist->root->start->id << testElist->root->end->id << endl;
    ////////////////////////////////////////////////////////////////
    // Test pop function
    cout << endl << "Testing pop" << endl;
    // Pop edge
    testElist->pop();
    // If root null, yay!
    if (testElist->root == nullptr) {
        cout << "Pop successful." << endl;
    } else {
        cout << "ERROR, pop unsuccessful." << endl;
    }

    ////////////////////////////////////////////////////////////////
    // Test searchByConns function
    cout << endl << "Testing searchByConns" << endl;
    // Create more edges
    edge *edgeAC = new edge(vertA, vertC, 4);
    edge *edgeBC = new edge(vertB, vertC, 6);
    edge *edgeAD = new edge(vertA, vertD, 2);
    edge *edgeCD = new edge(vertC, vertD, 3);
    // Push edges
    testElist->push(edgeAC);
    testElist->push(edgeBC);
    testElist->push(edgeAD);
    testElist->push(edgeCD);
    // Search for edge AD
    edge *searchEdge = testElist->searchByConns('A', 'D');
    // Print result
    cout << "SearchEdge: " << searchEdge->start->id << searchEdge->end->id << endl;

    ////////////////////////////////////////////////////////////////
    // Test remove function
    cout << endl << "Testing remove" << endl;
    // Remove AD
    testElist->remove('A', 'D');
    // Search where AD was. Should show BC
    cout << "root->listNext: " << testElist->root->listNext->start->id << testElist->root->listNext->end->id << endl;

    ////////////////////////////////////////////////////////////////
    // Test sortByWeight function
    cout << endl << "testing sortByWeight" << endl;
    // sort list
    testElist->sortByWeight();
    // Print list. Shoul show CD, AC, BC
    cout << "sorted list:" << endl;
    edge *printEdge = testElist->root;
    for (int i = 0; i < testElist->count; i++) {
        cout << printEdge->start->id << printEdge->end->id << ", ";
        printEdge = printEdge->listNext;
    }
    cout << endl;

    ////////////////////////////////////////////////////////////////
    // Garbage collection
    cout << endl << "Cleaning..." << endl;
    testElist->~edgeList();
    delete vertA;
    delete vertB;
    delete vertC;
    delete vertD;
    cout << "All clean!" << endl;

    ////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////
    // Test graph functions
    cout << endl << endl << "Testing graph" <<  endl;

    ////////////////////////////////////////////////////////////////
    // Test adding vert

     ////////////////////////////////////////////////////////////////
    //  Test adding edge

    ////////////////////////////////////////////////////////////////
    // Test dijkstra

    ////////////////////////////////////////////////////////////////
    // Test Kruskal

    return 0;
}
