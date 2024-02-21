#include <iostream>

#include "queue.hpp"

using std::cout;
using std::endl;

void valCheck(Queue *testQueue);

///////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////

int main() {

    // test and display queue values
    //create queue, test empty values
    Queue *testQueue = new Queue();

    //Queue testQueue;
    int startCount = testQueue->getCount();

    cout << "startCount: " << startCount << endl;

    //test enqueue, add a few nodes, check rear, front and count

    //one node added
    testQueue->enqueue(5);
    cout << "Add one node" << endl;
    valCheck(testQueue);

    //multiple nodes added (total 6)
    testQueue->enqueue(6);
    testQueue->enqueue(7);
    testQueue->enqueue(8);
    testQueue->enqueue(9);
    testQueue->enqueue(3);
    
    cout << "Add five more nodes" << endl;
    valCheck(testQueue);

    //test dequeue, remove some nodes, check rear, front and count
    

    
    testQueue->~Queue();
    return 0;
};

//value checking function for testing
    void valCheck (Queue *testQueue) {
        cout << "testQueue->getCount(): " << testQueue->getCount() << endl;
        Node checkRear = testQueue->peekRear();
        Node checkFront = testQueue->peekFront();
        cout << "testQueue->peekRear(): " << checkRear.value << endl;
        cout << "testQueue->peekFront(): " << checkFront.value << endl;
    };

///////////////////////////////////////////////////////////////////////////
// Node Function definitions
///////////////////////////////////////////////////////////////////////////

Node::Node(){
    this->next = nullptr;
    this->prev = nullptr;
    this->value = 0;

};

///////////////////////////////////////////////////////////////////////////
// Queue Function definitions
///////////////////////////////////////////////////////////////////////////

//Constructor
Queue::Queue(){
    this->rear = nullptr;
    this->front = nullptr;
    this->count = 0;
};

//destructor
Queue::~Queue(){
    // destroy all nodes
    while (count > 0) {
        this->dequeue();
    };

    //destroy queue
    delete this->rear;
    delete this->front;
    cout << "Queue deleted." << endl; 
};

// getCount function. returns count in queue
int Queue::getCount(){
    return this->count;
};

///////////////////////////////////////////////////////////////////////////
// Queueing functions
///////////////////////////////////////////////////////////////////////////

//add a new node to rear
void Queue::enqueue(int nodeVal) {
    //create node
    Node *newNode = new Node;
    newNode->value = nodeVal;

    if (count > 0) {

        //get current rear
        Node *currentRear = this->rear;

        //point node.next to rear
        newNode->next = currentRear;

        //set currentNode.prev to new rear
        currentRear->prev = newNode;

    };

    //set node to rear
    this->rear = newNode;

    // if count is 0, set node to front
    if (this->count == 0) {
        this->front = newNode;
    };

    // raise count by 1
    count++;

};

//remove and delete node from front
void Queue::dequeue() {
    //get front node
    Node *nodeToDel = this->front;

    //get front.prev
    Node *newFront = nodeToDel->prev;

    //set prev.next to nullptr
    newFront->next = nullptr;

    //delete front
    delete nodeToDel;
    //set front to prev
    this->front = newFront;

    //count decrement
    count--;

    //if count is now 0, set rear to nullptr
    if (count == 0) {
        this->rear = nullptr;
    };

};

///////////////////////////////////////////////////////////////////////////
// Check functions
///////////////////////////////////////////////////////////////////////////

//return rear node
Node Queue::peekRear() {
    Node *rearPtr = this->rear;
    return *rearPtr;
};

//return front node
Node Queue::peekFront() {
    Node *frontPtr = this->front;
    return *frontPtr;
};
