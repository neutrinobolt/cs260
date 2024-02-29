# Assignment 6: Binary Tree

Readme last updated 2/28/24

## Plan

### Basic layout

My binary tree will be made up of binary nodes (binNodes), each connected
to a left and right child node (and one parent possibly), and containing a
unique integer value. The left child node value will always be less than
the node's value, and the right child will always have a value greater than
or equal to that of the parent.

### Tree features

The tree will need an add function to add new nodes to the tree, a search
function to find if an input value is present in the tree, a remove
function to remove and reorder child nodes, and a traversal function to
map out all nodes in the tree. The tree will also need to have a pointer to
the first note in the tree (root) from which other functions can have a
starting place.

#### Add Function

Purpose: add new node in correct position.

Process:

- Start at root. set root to current node.

- Use recursive internal function (addStep) to check current node against new node.
If current node is nullptr, current node is now new node. If not:

- if current node > new node, run addStep on left child of current,
else run addStep on right child

Testing:
No root: print root, make sure it is correct node.
Yes root: Create smaller node, print left child. Create larger node, print
right child

#### Search Function

Purpose: determine if value is present in tree.

Process:

- Start at root. Set root to current.

- Set result to false bool as default answer

- Run recursive internal function (searchStep):

- if current == nullptr, break from conditionals

- check if current == check.
If true, set result to true

- if current > check, run searchStep on left child. else, run
searchStep on right child

- return result

Testing:
Expected true: add value to tree. search for value. expect to receive true.
Expected false: search for value that is not in lis. Expect to receive false.

#### Remove function

Purpose: remove node of input value from tree. reorder child nodes.

Process:

- Determine how many children nodetoDel has

- Condition 1: nodeToDel has no children (left and right are nullptr)

Delete nodeToDel, if node was less than parent, parent left child becomes
nullptr, else parent right child becomes nullptr

- Condition 2: NodetoDel has 1 child (left or right are nullptr)

Get child. If parent > child, child = parent's left child. Else
child = parent's right child

- Condition 3: nodeToDel has 2 children

1. Find successor. Run recursive findSuccessor function on nodeToDel's
right child

2. Give successor all of nodeToDel's properties (except value, of course)

3. delete nodeToDel

- findSuccessor: if left child is nullptr, return node. Else, run findSuccessor
on left child.

testing:

- Test if nodeToDel is not in tree: try to remove a node not in the tree.
Should return error

- Test condition 1 removal: remove node with no children. Node's parent should
have nullptr where node was

- Test condition 2 removal: remove node with 1 child. parent should have node's
child where node was

- Test condition 3 removal: remove node with 2 children. Expected successor
should be where node was

#### Traversal function (recursive)

Purpose: Traverse tree, collecting each node value in order, then return
ordered list of nodes in ascending order

Process (Left, View, Right):

- Start at root

- If input node's left child is not nullptr, run traversal on left child

- View (Collect node value, add to list)

- If input node's right child is not nullptr, run traversal on right child

Testing:
Create tree with several nodes (7-ish?)
run traversal on tree, print result
should display all values in tree in ascending order

### all public functions

add
search
remove
traversal (inOrder)

### all private functions

addStep
searchStep
findSuccessor
