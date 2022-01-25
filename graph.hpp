#include <iostream>
#include <stdlib.h>
#include "classe.hpp"


using namespace std;

#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
	public :
	vector<arcs> arc;
	int nbarcs;
	Graph(){
		nbarcs = 0;
		arc = new arc[nbarcs];
	}

	Graph(const Graph& graphe){
		nbarcs = graphe.nbarcs;
		for (int i = 0; i < nbarcs; i++) arcs[i] = graphe.arcs[i];
	}
	
	Graph& add(Graph& graphe, arc& arc);
	Graph& remove(Graph& graphe,arc& arc);

}

#endif