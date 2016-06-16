/* Armin Akhbari
*	8285298
*/
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Edge.h"
#include "UnionFind.h"
#include <stdio.h>
using namespace std;

class Graph{
	int verticesNumber;
	int edgeNumber;
	int remainingEdge;
	Edge *Edges;

	
	/***************Heap Sort*******************/
	bool myCompare(Edge x, Edge y);
	void heapsort(int n);
	void percolateDown(int k, int N);
	void swap(Edge& a, Edge& b);
	/******************************************/



public:
	
	Graph();
	Graph(int v, int e);
	
	Graph kruskalMST();
	void addEdges(int index, int s, int d, int w);
	void print();
	void setRemainingEdge(int i);

	
};
#endif

