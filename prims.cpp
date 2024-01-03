#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int findMinKey(int key[], bool mstSet[], int vertices) {
    int minKey = INF, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(vector<vector<int>>& graph, int vertices) {
    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];

    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0; // Start with the first vertex

    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edges \tWeight\n";
    for (int i = 1; i < vertices; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

int main() {
    int vertices = 5; // Example with 5 vertices

    // Sample graph with weights
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, vertices);

    return 0;
}
