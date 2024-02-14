#include <iostream>

#include "queue.hpp"

using std::cout;
using std::endl;

int main() {
    // test and display queue values
    //create queue, test empty values
    Queue *testQueue = new Queue();
    //Queue testQueue;
    int startCount = testQueue->getCount();

    cout << "testQueue.getCount(): " << startCount << endl;

    //test enqueue, add a few nodes, check rear, front and count


    return 0;
}