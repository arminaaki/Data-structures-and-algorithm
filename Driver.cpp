/* Armin Akhbari
*	8285298
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
	
	//	std::ifstream infile("input9.txt");
		string line;
		int vertices, numberOfEdges, edgeS, edgeD;
		int edgeW;

		getline(cin, line);
		istringstream buffer(line);
		buffer >> vertices >> numberOfEdges;

		Graph myGraph(vertices, numberOfEdges);

		for (int i = 0; i < numberOfEdges; ++i)
		{



			getline(cin, line);
			buffer.clear();
			buffer.str(line);
			buffer >> edgeS >> edgeD >> edgeW;
			myGraph.addEdges(i, edgeS, edgeD, edgeW);


		}
		Graph g2 = myGraph.kruskalMST();
		g2.print();
	

	return 0;

	}
