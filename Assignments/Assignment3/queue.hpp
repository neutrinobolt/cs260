#include "node.hpp"

class Queue {

    Node *rear;
    Node *front;
    int count;


    public:

        //construction
        Queue queue();

        //queue methods
        void enqueue();
        void dequeue();
        Node peekRear();
        Node peekFront();
        int getCount();
};