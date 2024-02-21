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

## file notes

I wasn't sure how better to split the project into separate files
besides using header files like I did. I'll probably have to go back
and rewatch some sessions to figure that out. However, I still made
it work just fine. Testing is conducted in the main function by
making sure the correct values are returned. This goes from lines 16-72
in main.cpp. All queue related functions are defined in lines 95-end.
I'm not entirely sure garbage collection (called line 71, defined lines 107-118)
works like I want it to, but its print statements print so I assume the
preceding lines are working properly.
