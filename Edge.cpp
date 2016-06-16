#include "Edge.h"

/* Armin Akhbari
*	8285298
*/
#ifndef EDGE_CPP
#define EDGE_CPP


	Edge::Edge(int s, int d, int w){
		source = s;
		destination = d;
		weight = w;
	}
	Edge::Edge(){
		source = 0;
		destination = 0;
		weight = 0;
	}

	/**
	* Simple setter.
	* @param source
	*/
	void Edge::setSource (int source) { 
		this->source = source ;
	}
	/**
	* Simple getter.
	* @return source
	*/
	int Edge::getSource() { 
		return this->source ;
	}
	/**
	* Simple setter.
	* @param destination
	*/
	void Edge::setDestination(int destination) {
		this->destination = destination ;
	}
	/**
	* Simple getter.
	* @return destination
	*/
	int Edge::getDestination(){
		return this->destination; }
	/**
	* Simple setter.
	* @param weight
	*/
	void Edge::setWeight(int weight) {
		this->weight = weight ;
	}
	/**
	* Simple getter.
	* @return weight
	*/
	int Edge::getWeight() {
		return this->weight; 
	}

	

#endif