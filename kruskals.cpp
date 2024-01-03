#include<bits/stdc++.h>
using namespace std;

#define MAX 1001

using namespace std; 

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalMST(vector<Edge>& edges, int vertices) {
    vector<Edge> result;
    int e = 0, i = 0;
    
    sort(edges.begin(), edges.end(), compare);
    
    Subset subsets[vertices];
    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < vertices - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];
        
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        
        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }
    
    cout << "Edges \tWeight\n";
    for (i = 0; i < result.size(); i++)
        cout << result[i].src << " - " << result[i].dest << "\t" << result[i].weight << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<Edge> edgeList(edges);
    cout << "Enter source, destination, and weight for each edge:\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i].src >> edgeList[i].dest >> edgeList[i].weight;
    }

    kruskalMST(edgeList, vertices);

    return 0;
}
