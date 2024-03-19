#include <iostream>

#include "hash.hpp"

using std::cout;
using std::endl;

// Function for checking contents of table
void tableCheck (hTable *testTable) {
    for (int index = 0; index < 10; index++) {
        cout << testTable->hashArray[index] << ", ";
    }
    cout << endl;
}

int main() {
    ////////////////////////////////////////////////////////////////
    // Create and test creation of hTable
    hTable *testTable = new hTable(10);
    cout << "Checking creation of testTable:" << endl;
    tableCheck(testTable);
    
    ////////////////////////////////////////////////////////////////
    // Test hash function
    cout << endl << "Testing hash" << endl;
    // test values: "Fudge" (Expect 1) and "Caramel" (Expect 3)
    cout << "hash('Fudge'): " << testTable->hash("Fudge") << endl;
    cout << "hash('Caramel'): " << testTable->hash("Caramel") << endl;

    ////////////////////////////////////////////////////////////////
    // Test Insert function
    cout << endl << "Testing insert" << endl;
    // Generic insertion
    testTable->insert("Fudge", "Caramel");
    tableCheck(testTable);
    // Second insertion
    testTable->insert("Caramel", "Fudge");
    tableCheck(testTable);
    // Collision (Insert at next available slot)
    testTable->insert("G", "Toffee");
    tableCheck(testTable);
    // Multiple collisions
    testTable->insert("Q", "Sweets");
    tableCheck(testTable);

    ////////////////////////////////////////////////////////////////
    // Test valCheck function
    cout << endl << "Testing valCheck" << endl;
    // Test false result
    bool checkFalse = testTable->valCheck("A");
    cout << "valCheck(A): " << checkFalse << endl;

    // test true result
    bool checkTrue = testTable->valCheck("Fudge");
    cout << "valCheck(Fudge)" << checkTrue << endl;

    ////////////////////////////////////////////////////////////////
    // Test remove function
    cout << endl << "Testing remove" << endl;
    // Test value not present error
    testTable->remove("boop", "None");

    // Test remove at given index
    testTable->remove("Fudge", "Caramel");
    tableCheck(testTable);

    // Test remove after linear probe
    testTable->remove("Q", "Sweets");
    tableCheck(testTable);

    ////////////////////////////////////////////////////////////////
    // Test resizing function
    // cout << endl << "Testing resize" << endl;

    // // Add values to half size (Add 3 more to bring count to 5)
    // testTable->insert("A" ,"Beep");
    // testTable->insert("B", "Boop");
    // // This one should trigger a resize
    // testTable->insert("C", "Bop");
    // // Should now receive resizing messages


    // // Print table. Should be of size 20, with newly calculated val indices.
    // tableCheck(testTable);

    ////////////////////////////////////////////////////////////////
    // Garbage collection
    cout << endl << "Cleaning up..." << endl;
    testTable->~hTable();
    cout << "reached end of test." << endl;

    return 0;
} 