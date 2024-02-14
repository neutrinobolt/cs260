#include "node.hpp"

class Queue {

    Node *rear;
    Node *front;
    int count;

    Queue();

    public:

        //queue methods
        void enqueue();
        void dequeue();
};