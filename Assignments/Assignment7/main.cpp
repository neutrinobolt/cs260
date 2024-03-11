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

    ////////////////////////////////////////////////////////////////
    // Test lookup function

    ////////////////////////////////////////////////////////////////
    // Garbage collection
    testTable->~hTable();
    cout << "reached end of test." << endl;

    return 0;
} 