#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v, bool visited[]);
	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void printSCCs();
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;

	for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	Stack.push(v);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::printSCCs()
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	Graph transposed = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	while (!Stack.empty())
	{
		int v = Stack.top();
		Stack.pop();

		if (!visited[v])
		{
			transposed.DFS(v, visited);
			cout << endl;
		}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(1, 3);
	g.addEdge(3, 4);

	cout << "Strongly Connected Components:\n";
	g.printSCCs();

	return 0;
}
