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

    //test dequeue, remove some nodes, check rear, front and count

    return 0;
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


    //destroy queue
    delete this;
};

// getCount function. returns count in queue
int Queue::getCount(){
    return this->count;
};


//add a new node to rear
void Queue::enqueue(int nodeVal) {
    //create node
    Node *newNode = new Node;

    //point node.next to rear

    // set node to rear

    // if count is 0, set node to front

    // raise count by 1

};

void Queue::dequeue() {

};

Node Queue::peekRear() {

};

Node Queue::peekFront() {

};

int Queue::getCount() {

};
