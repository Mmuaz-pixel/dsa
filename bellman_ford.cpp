#include <iostream>
#include <vector>
#include <climits>

struct Edge
{
	int source, destination, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(std::vector<Edge> &edges, int numVertices, int source)
{
	std::vector<int> distance(numVertices, INT_MAX);
	distance[source] = 0;

	// Relax edges repeatedly
	for (int i = 0; i < numVertices - 1; ++i)
	{
		for (const auto &edge : edges)
		{
			if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
			{
				distance[edge.destination] = distance[edge.source] + edge.weight;
			}
		}
	}

	// Check for negative cycles
	for (const auto &edge : edges)
	{
		if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
		{
			std::cout << "Graph contains negative cycle. Bellman-Ford cannot guarantee correct results.\n";
			return;
		}
	}

	// Print the shortest distances
	std::cout << "Shortest distances from the source vertex (" << source << "):\n";
	for (int i = 0; i < numVertices; ++i)
	{
		std::cout << "To vertex " << i << ": " << distance[i] << "\n";
	}
}

int main()
{
	// Example usage of Bellman-Ford algorithm

	// Define the graph as a set of edges
	std::vector<Edge> edges = {
		{0, 1, 5},
		{0, 2, 4},
		{1, 3, 3},
		{2, 1, 6},
		{2, 3, 7},
		{3, 0, 2},
		{3, 4, 4},
		{4, 3, 1}};

	int numVertices = 5;  // Number of vertices in the graph
	int sourceVertex = 0; // Source vertex for Bellman-Ford algorithm

	// Call Bellman-Ford algorithm
	bellmanFord(edges, numVertices, sourceVertex);

	return 0;
}
