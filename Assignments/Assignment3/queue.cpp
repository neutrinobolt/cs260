#include "node.hpp"

class Queue {

    Node *rear;
    Node *front;
    int count;

    public:

        Queue() {
            rear = nullptr;
            front = nullptr;
            count = 0;
        };

        //queue methods
        void enqueue(int nodeVal) {
        
            // create node

            //point next to rear

            //set rear to new node

            if (this->count == 0) {
                //set front to new node
            }

            // count++

        };

        void dequeue() {

        };

        // Node peekRear() {
        //     //return this->rear;
        // };

        // Node peekFront() {

        // };

        int getCount() {
            return this->count;
        };
};