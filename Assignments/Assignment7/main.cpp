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
    hTable *testTable = new hTable;
    cout << "Checking creation of testTable:" << endl;
    tableCheck(testTable);
    
    ////////////////////////////////////////////////////////////////
    // Test hash function
    // test values: "Fudge" (Expect 1) and "Caramel" (Expect 3)
    cout << "hash('Fudge'): " << testTable->hash("Fudge") << endl;
    cout << "hash('Caramel'): " << testTable->hash("Caramel") << endl;

    ////////////////////////////////////////////////////////////////
    // Test Insert function
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
    
    // Test false result
    bool checkFalse = testTable->valCheck("Caramel");
    cout << "valCheck(Caramel): " << checkFalse << endl;

    // test true result
    bool checkTrue = testTable->valCheck("Fudge");
    cout << "valCheck(Fudge)" << checkTrue << endl;

    ////////////////////////////////////////////////////////////////
    // Test remove function

    // Test value not present error
    testTable->remove("boop", "None");

    // Test remove at given index
    testTable->remove("Fudge", "Caramel");
    tableCheck(testTable);

    // Test remove after linear probe
    testTable->remove("Q", "Sweets");
    tableCheck(testTable);

    ////////////////////////////////////////////////////////////////
    // Garbage collection
    testTable->~hTable();
    cout << "reached end of test." << endl;

    return 0;
} 