#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int src, dest, weight;
};


class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


bool compareEdges(const Edge &e1, const Edge &e2) {
    return e1.weight < e2.weight;
}


void kruskalMST(vector<Edge> &edges, int numVertices) {
    
    sort(edges.begin(), edges.end(), compareEdges);

    
    DisjointSet ds(numVertices);

    
    vector<Edge> mst;
    int mstWeight = 0;

    
    for (const Edge &edge : edges) {
        
        int rootSrc = ds.find(edge.src);
        int rootDest = ds.find(edge.dest);

        
        if (rootSrc != rootDest) {
            mst.push_back(edge);
            mstWeight += edge.weight;
            ds.unionSet(rootSrc, rootDest);
        }

        
        if (mst.size() == numVertices - 1) {
            break;
        }
    }

    
    cout << "Minimum Cost Spanning Tree:" << endl;
    for (const Edge &edge : mst) {
        cout << "Edge (" << edge.src << " -> " << edge.dest << ") with weight " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}


int main() {
    

    
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    
    int numVertices = 4;

    
    kruskalMST(edges, numVertices);

    return 0;
}
