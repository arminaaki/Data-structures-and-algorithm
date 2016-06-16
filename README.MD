Command Line Arguments
----------------------
before running the program, it's required to run make.
Example:  ./prog2<intput.txt>output.txt

This program implements the kruskal's Algorithm and finds the cheapest minimum spanning tree in the given graph by the input.
Kruskal’s algorithm begins by sorting the edges in increasing order of weight, and then scans edges in this order to determine whether they should be added to MST.
Union find is used in the algorithm to detemrmine if a cycle exists.
Method of union is (union by rank), and path compression is done once find operation is executed.

Sorting Algorithm: Heap sort is implemented with the running time of O(mlogm), where m is number of edges.

.h files
--------
Edge.h: 
UnionFind.h:
Graph.h:

.cpp files
----------
Driver.cpp: 
Edge.cpp:
Graph.cpp: Kruskal method, and heap sort algorithm  is located in this file.
UnionFind.cpp: find and union operation is locate in this file

