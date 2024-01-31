# Assignment 2: Design

## 1. queue structure design

- a queue is a list of items where items are added onto the opposite end as they
are removed. Therefore, in addition to whatever other information you wish to
store, an individual object needs to know where in the list it resides (and item
id), and the location of the next value in the list.
Then we can find the first item by searching for the item with an id of 1.
The last item can be found with a simple function that starts at the beginning
of the list and passes through each list item until it reaches the end, and
returns the last value it found.

- The queue will need to be able to add new objects to the back (enqueue)
and remove objects from the front (dequeue).

    1. Adding on new objects should be easy enough: find the item id of the
current last item in the list (using the function previosly specified),
create a new object with an id 1 higher than the last object, and change
the pointer of the old last object to be the location of the new one.

    2. To dequeue, you would want to remove the first item, and then shift the
item id's of all the rest of the objects down by 1.

## 2. New data structure

- This list will have the same linked-list structure as the queue, including
the function to find the last objet in the list.

- This list will need two functions: insert and delete.

    1. insert
        - This function will require to first know the item id to insert at. It will
    then adjust all values at that id and higher up by 1. It will then create
    the new value with a pointer to the item previously residing at that id, and will
    change the pointer on the item before it to properly point to the new item.

    2. delete
        - This function works similarly. First delete/remove the item, and
        move down all item id's above the one specified by one. Finally, take
        the item of id one lower than the one to be removed and change its
        pointer to point to the item one id above the item to be removed.
