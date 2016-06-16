/* Armin Akhbari
*	8285298
*/
#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <iostream>
#include "Edge.h"

class UnionFind{

	int *mySets;
	int *rank;
	int size;
	
	void buildSet();
public:

	void myUnion(int set1, int set2);
	int myFind(int element1);
	UnionFind();
	UnionFind(int verticesNumber);
	

};



#endif

