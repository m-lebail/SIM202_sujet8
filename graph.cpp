#include "graph.hpp"

	Graph& Graph::add(Graph& graphe, arc& arc){
		this.nbarcs++;
		this.arcs[nbarcs-1] = arc;
		return *this;
	}

	Graph& Graph::remove(Graph& graphe, arc& arc){
		this.nbarcs--;
		return *this;
	}