#include "Graph.hpp"

int main()
{
	Graph graph;

	std::cout << graph << std::endl;

	graph.addPoint(0, 0);
	graph.addPoint(2, 2);
	graph.addPoint(4, 2);
	graph.addPoint(2, 4);

	std::cout << graph << std::endl;
	
	graph.display();
}
