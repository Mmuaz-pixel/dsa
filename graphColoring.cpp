#include <iostream>
#include <vector>
#include <algorithm>

class Graph
{
private:
	int V;									 // Number of vertices
	std::vector<std::vector<int>> adjMatrix; // Adjacency matrix

public:
	// Constructor
	Graph(int vertices) : V(vertices), adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

	// Function to add an edge to the graph
	void addEdge(int v, int w)
	{
		adjMatrix[v][w] = 1;
		adjMatrix[w][v] = 1;
	}

	// Function to color the graph using greedy algorithm
	void colorGraph()
	{
		std::vector<int> result(V, -1); // Stores the color assigned to each vertex

		// Assign the first color to the first vertex
		result[0] = 0;

		// Process the remaining V-1 vertices
		for (int u = 1; u < V; u++)
		{
			// Initialize the availability of colors for the current vertex
			std::vector<bool> available(V, true);

			// Check colors assigned to all adjacent vertices and mark them as unavailable
			for (int v = 0; v < V; v++)
			{
				if (adjMatrix[u][v] == 1 && result[v] != -1)
					available[result[v]] = false;
			}

			// Find the first available color
			int color;
			for (color = 0; color < V; color++)
			{
				if (available[color])
					break;
			}

			result[u] = color; // Assign the found color to the current vertex
		}

		// Print the results
		std::cout << "Vertex \t Color" << std::endl;
		for (int u = 0; u < V; u++)
		{
			std::cout << u << "\t " << result[u] << std::endl;
		}
	}
};

int main()
{
	// Create a graph with 4 vertices
	Graph graph(4);

	// Add edges to the graph
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);

	// Color the graph
	graph.colorGraph();

	return 0;
}
