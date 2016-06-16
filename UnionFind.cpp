/* Armin Akhbari
*	8285298
*/
#include "UnionFind.h"
UnionFind::UnionFind() {
	mySets = NULL;
	size = 1;
}
UnionFind::UnionFind(int number) {

	size = number + 1;
	
		mySets = new int[size];
		rank = new int[size];
	/* it initializes the set */
	buildSet();
}

/// The initializer.
/**
* 
* It sets the rank of every element to zero   
* It sets the parent of every element to the element itself
*/
void UnionFind::buildSet(){
	
	for (int i = 1; i < size; ++i){
		mySets[i] = i;
		rank[i] = 0;

	}


}
/// It performs find operation on a given element, path compression.
/**
* @param element1
*    First element
* @return int
*	It returns the root of the set where the element exists 
*/
int UnionFind::myFind(int element1){
		if (mySets[element1] == element1)
			return element1;
		else
			//Path compression
			return mySets[element1] = myFind(mySets[element1]);
}

/// It performs union operation on two given sets, and it unions based of the height of every set.
/**
* @param set1
*    First set
* @param set2
*	Seccond set
*/
void UnionFind::myUnion(int set1, int set2){
	//it finds the root of set1
	int myRoot1 = myFind(set1);

	//it finds the root of set2
	int myRoot2 = myFind(set2);

	//mRoot2 is deeper
	if (rank[myRoot2] < rank[myRoot1]) 
		mySets[myRoot1] = myRoot2; 
	//mRoo1 is deeper
	else if (rank[myRoot1] < rank[myRoot2]) 
			mySets[myRoot2] = myRoot1; 

	//roots have the same height
	else {
			--rank[myRoot1]; //Height is now updated
			mySets[myRoot2] = myRoot1; 
	}

}