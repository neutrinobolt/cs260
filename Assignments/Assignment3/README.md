# Assignment 3: Linked queue

## Plan

I will need to create a queue class that is made up of individual node objects.
These nodes will need to have their own values and pointers
that can be set to the previous and next nodes in the queue.
The queue will also need to have pointers to the front and rear nodes which are
updated as nodes are enqueued and dequeued, and a count totalling
how many nodes are currently in the queue.

Enqueue:
This will add nodes to the rear.

- Create new node
- assign pointer to rear
- new node becomes rear
- count increments by 1

Additionally, if count is now 1:

- Set front to rear

Dequeue:
will remove nodes from front.

- set aside current front node
- set front to node behind front
- delete node set aside
- decrement count by 1

Additionally, if count is now 1:

- set rear to nullptr
