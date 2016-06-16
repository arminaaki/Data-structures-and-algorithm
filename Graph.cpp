/* Armin Akhbari
*	8285298
*/
#include "Graph.h" 


Graph::Graph(){

	verticesNumber = 0;
	edgeNumber = 0;
	remainingEdge = 0;
}
Graph::Graph(int v, int e){

	verticesNumber = v;
	Edges = new Edge[e];
	edgeNumber = e;
	remainingEdge = 0;
}
/**
* It perfoms a swap operation on two edges
*    @param  a
*	the refrence of first edge
*	 @param b
*	the refrence of seccond edge
*/
void Graph::swap(Edge& a, Edge& b){

	Edge temp = a;
	a = b;
	b = temp;

}
/**
* It perfoms a swap operation on two edges
* @param index
*    edge index
* @param s
*	edge source
* @param d
*	edge destination
*@param w
*	edge weight
*/
void Graph::addEdges(int index, int s, int d, int w){
	if (s <= verticesNumber&&d <= verticesNumber&& s>=0)
	{
		Edges[index].setSource(s);
		Edges[index].setDestination(d);
		Edges[index].setWeight(w);
	}
	else
		edgeNumber--;
}
/**
* It implenmts Kruskal algorithm to find the minimum spaning tree
* Union find is incorpreated in this algorithm
*/
Graph Graph::kruskalMST(){
	
	//Sorting by the weight
	heapsort(edgeNumber);

	UnionFind myUnionFind(verticesNumber);
	//Every tree without a cycle has n vertices and at most n-1 edges.
	Graph G1(verticesNumber, verticesNumber - 1);
	//
	int counter = 0;

	for (int i = 0; i < edgeNumber; ++i)
	{
		int source = Edges[i].getSource();
		int destination = Edges[i].getDestination();
		int weight = Edges[i].getWeight();
		//If they are both element of a same subset, there exists a path. Therefore it creates a cycle if that edge is added.
		if (myUnionFind.myFind(source) != myUnionFind.myFind(destination)){

			G1.addEdges(counter++, source, destination, weight);
			myUnionFind.myUnion(source, destination);
			printf("Edge (%d,%d) successfully inserted\n", source, destination);
		}
		else
			printf("Edge (%d,%d) creates cycle\n",source,destination);

	}
	//it stores the total number of edges.
	G1.setRemainingEdge(counter);

	return G1;
}
/**
* comparing two edge based on their size
* @param x
*    First edge
* @param y
*	 Seccond edge
* @return boolean
*	It returns true if x<y else returns false
*/
bool Graph::myCompare(Edge x, Edge y){

	if (x.getWeight() < y.getWeight())
		return true;
	else if (x.getWeight() == y.getWeight()){

		if (x.getSource() < y.getSource())
			return true;
		else if (x.getSource() == y.getSource()){
			if (x.getDestination() < y.getDestination())
				return true;
		}

	}
	return false;

}
/**
* The algorithm sorts the the array using heap sort
* @param n
*    The size of the heap
* 
*/
void Graph::heapsort(int n){
	/* building heap */
	for (int k = n / 2; k >= 0; k--) {
		percolateDown(k, n);
	}

	while (n > 1) {
		//root is the maximum element of the heap. Thus it will be swapped with the last element.
		swap(Edges[n - 1], Edges[0]);
		
		percolateDown(0, n - 1);

		// an element sorted. The size of the hep is decreased by 1
		n--;
	}
}
/**
* It percolates down from the given node in the heap
* @param k 
*    node of the heap
* @param N
*	The size of the heap
*/
void Graph::percolateDown(int k, int N){
	while (k * 2 + 1 < N) {
		//
		int child = 2 * k + 1;

		//Confirming the largest child among the two
		if ((child + 1 < N) && myCompare(Edges[child], Edges[child + 1]))
			child++;

		if (myCompare(Edges[k], Edges[child])) {
			swap(Edges[child], Edges[k]);
			k = child;
		}

		else
			break;
	}
}
/**
* If the resultant graph is mft
*    It prints out edges's source and destination
*	 It calculates the total weight of mft
* Otherwise
*	It prints out ERROR: MST not found.
*/
void Graph::print(){
    int totalCost = 0;
	if (remainingEdge == verticesNumber - 1){
		for (int i = 0; i < edgeNumber; ++i){
			printf("%d %d\n", Edges[i].getSource(), Edges[i].getDestination());
			totalCost += Edges[i].getWeight();
		}
		cout << totalCost;
	}
	else
		cout << "ERROR: MST not found." << endl;
}
/**
* Simple setter
* @param i
*	Edge number of graph
* 
*/
void Graph::setRemainingEdge(int i)
{
	remainingEdge = i;
}
