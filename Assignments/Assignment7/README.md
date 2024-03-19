# Assignment 7: Hash table

Last updated 3/19/24

## Plan

For this assignment I will create a simple hash table that can take a key/value
pair, hash the value, and store the key at the hashed index. For this I will
need to create a basic hash function, an insert function, and a lookup
function. Then, I need to use this base to create a more complex hash table.
For that table I will attempt to implement a removal function,  a method
for dynamically resizing the hash table, or possibly a way to handle collisions
using linear probing.

### Simple table

Table will need:

- array for storing values (Maybe resizable later)
- hash function
- insert function
- lookup function

#### Hash function

This function must be able to take in a string and output an integer to be used
as the index where a value is to be kept. It'll be pretty simple. Just add
together all the ASCII values of each character and return that % the array
size.

This can be tested by checking if the given result (check by printing) is
correct.

#### Insert function

This function takes in a key and a value. It hashes the key, then places the
value at that index in the array. For now, collisions will be handled by just
replacing the pre-existing value.

This can be tested by printing the array and making sure the input value is
there.

#### Lookup function

This function, when called, will return true if the input value is present in
the table. It will check each index in the array and if the value is ever
found, the function will return true. else, the function will return false.

This can be tested by checking that a non-existant value returns false
and and existing value returns true.

### Complex table

So, the simple table took me no time at all to whip up. Time to add some spice!

#### Remove function

- Given a key, replace the associated value in the array with an empty string.
- Test by printing the array.

#### Linear probing collision handler

- When inserting a new value, check if intended index has a value in it. if so,
attempt to insert value at next index, making same check. continue until empty
empty index is found.
- again, test by printing the array.

#### Dynamic resizing

- For this I may need to make some heavy adjustments to my existing code.
- When inserting values, add key to a linked list of keys.
- When array reaches half full, resize.
- extract keys and values, place them in separate arrays in matching order.
- create new array with size double that of old one
- reinsert keyk-val pairs to new array

## Results

Overall, I am pleased with the final result. I wasn't able to get the resizing
function to work properly, though. I kept bad_alloc errors and couldn't figure
out how to fix it. I have left the code and files used to implement the function
in main.cpp, lines 72-84, and hash.cpp, lines 68-72. These files are what
called the function, and all keylist and keylink files were only used to try to
make this function work. They are all still called, though they
serve no actual purpose.

You can find the hash, insert, remove, and valcheck functions all in hash.cpp,
lines 31-40, 41-75, 76-103, and 104-115 respectively. Included in the insert
and remove functions you will find provisions made for collisions with a
linear probing technique.