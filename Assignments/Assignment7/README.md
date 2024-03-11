# Assignment 7: Hash table

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
