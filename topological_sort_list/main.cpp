#include <iostream>
#include "graph.h"


int main(){
	Graph G, SortedG;
	int n = G.FormGraph();
	G.Print(n);
	G.SortGraph(SortedG);
	SortedG.Print(n);
	std::cin.get();
	return 0;
}
/*
1 2
1 3
4 2
4 3
2 3

*/