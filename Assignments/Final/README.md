# Final Project

Last Updated 3/22/24

## Important note (Happy)

The project is finished now! See below for my original plans and final
results.

## Plan

The plan is to create a working graph capable of inserting new vertices,
inserting new edges connecting those vertices, an algorithm for finding
the shortest path between two vertices (Dijkstra) and an algorithm for
finding a minimum spanning tree (Kruskal). Such a tool could be used for
mapping and pathfinding in a GPS, or similar functions in a game map.

### Contents

Graph object will include:

- Linked list containing vertices
- Linked list containing edges
- addVert function
- addEdge function
- dijkstra pathfinder algorithm
- kruskal spantree algorithm

vertex object:

- vertex id (letter)
- distance (for dijkstra)
- previous (for dijkstra)
- degree (for kruskal)
- listNext

edge object:

- endpoint vertices (Start and end?)
- integer weight
- listNext

Vertex list:

- root
- count
- push function
- pop function
- search function
- remove function
- swap function
- sort function (for dijkstra and kruskal)

edge list:

- see vertex list, but formatted to hold edges instead

### Functions

#### addVert(vertexId)

- This function creates a new vertex with input id and pops it onto the vertex
list.

- Testing: print id of vertlist root

#### addEdge(start, end, weight)

- This function creates a new edge connected to vertices start and end with
input weight.

- Testing: print start, end, weight of edgelist root

#### pathFinder (start, end)

- This function will calculate the shortest path between vertices start and
end. If no path can be found, return false.
Else return a vertex list of the path steps from start to end.

1. set all vertex distances to some very high number (500?). Set distance
on end to 0.

2. Create secondary vert list, sort by distance. Set a count to 0

3. While secondary verts is not empty:

    - Sort vert list in ascending distance order
    - get smallest distance vertex, all edges connecting to verts in secondary
    list. place edges in new edge list
    - for all edges in new edge list:
        - check distance of destination vert. if distance is greater than
        source edge distance + weight of connecting edge, destination vert.
        distance becomes source dist + edge weight. set destination previous
        to source.
    - Remove source edge from secondary list
    - add 1 to count. If count is greater than main vertlist count, return false

4. When done with step 3, secondary vert list should be empty. Now create a new
secondary vert list. Starting at end, add every consecutive vertex's prev to
new list until start is added. If nullptr is reached before start, return false
else return this list and start's distance

- testing: print steps in list and total distance

#### minSTree ()

1. Create a new edge list. set all vertex degrees to zero.

2. Sort edge list by weight. For edge in the list:

    - if degree of both endpoints is not 2:
        - add edge to new edge list
        - add 1 to degree of both endpoints

3. return newly created edgelist.

- Testing: print new list.

File "Dijkstra_Animation.gif" is used for a reference of the final graph
object. vertex ids will be given letter names instead of numbers.

## Results

Finally, I managed to get it working! While my pathfinding algorithm doesn't
return the shortest path, it does correctly return if a path is achievable
or not, and makes it so a path can be traced from start to end. This I am
considering a success. I am keeping track of the vertices and edges in linked
lists, so the search complexity of the pathfinding and search algorithms
probably take a pretty big hit. Sorting has O(n) i believe, and pathfinding
sits at O(n**2), I think? This is because I repeatedly reference secondary
lists for the algorithm. Not the most efficient thing in the world. If
I were to use hash tables instead of linked lists that would probably
make it a lot faster.

### Notable function lines

#### Testing lines

- Vertlist: lines 11-111
- Edgelist: lines 115-193
- Basic graph functions: lines 197-237
- pathFind: lines 240-254
- minstree: lines 257-272

#### Function definitions

- pathfind: lines 40-175
- minstree: lines 176-215

Find vertlist and edgelist function definitions in files vertlist.cpp
and edgelist.cpp, respectively. Function definitions are practically the same.
