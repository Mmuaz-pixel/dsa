#include <iostream>
#include <queue>

using namespace std;

#define TOTAL_NODES 8

void BFS(int startingPoint, int a[TOTAL_NODES][TOTAL_NODES])
{
    int visited[TOTAL_NODES] = {0, 0, 0, 0, 0, 0, 0, 0}; 
    cout << "Starting from Node " << startingPoint << " : "; 
    queue<int> q1;
    int i = startingPoint - 1; // starting node
    cout << i + 1; // printing the first node
    visited[i] = 1; // marking the starting node visited
    q1.push(i); // pushing first node in queue so that we will visit its neighbours now 

    while (!q1.empty())
    {
        int node = q1.front();
        q1.pop();
        for (int j = 0; j < TOTAL_NODES; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0) // condition to check if there is connection and it is not visited 
            {
                q1.push(j);
                cout << " -> " << j + 1; // printing the node we visit 
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    int Adjacency_Matrix[TOTAL_NODES][TOTAL_NODES] = { 
        {0, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1}
    };

    BFS(2, Adjacency_Matrix); // calling the bfs function 
    return 0;
}
