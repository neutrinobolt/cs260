#include "node.hpp"

class Queue {

    Node *rear;
    Node *front;
    int count;


    public:

        //construction
        Queue();
        //deconstruction
        ~Queue();

        //queue methods
        void enqueue(int nodeVal);
        void dequeue();
        Node peekRear();
        Node peekFront();
        int getCount();
};