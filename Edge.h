/* Armin Akhbari
*	8285298
*/
#ifndef EDGE_H
#define EDGE_H


	class Edge{

		int source;
		int destination;
		int weight;
		

	public:
		void setSource(int source);
		void setDestination(int destination);
		void setWeight(int weight);
		int getSource();
		int getDestination();
		int getWeight();


	
		Edge(int s, int d, int w);
		Edge();
		

	};



#endif

