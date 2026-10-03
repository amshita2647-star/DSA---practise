#include <stdio.h>
#include <stdlib.h>

#define MAXV 100
#define MAXE 500


// ---------------- EDGE STRUCTURE ----------------

struct Edge
{
    int u;
    int v;
    int wt;
};


// ---------------- DISJOINT SET ----------------

int parent[MAXV];
int size[MAXV];


// Initialize DSU
void makeSet(int V)
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}


// Find ultimate parent
int findUPar(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    // Path compression
    parent[node] = findUPar(parent[node]);

    return parent[node];
}


// Union by Size
void unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    // Already in same component
    if (ulp_u == ulp_v)
    {
        return;
    }

    if (size[ulp_u] < size[ulp_v])
    {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else
    {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}


// ---------------- SORTING FUNCTION ----------------

// qsort needs a comparison function
int compareEdges(const void *a, const void *b)
{
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;

    return edge1->wt - edge2->wt;
}


// ---------------- KRUSKAL ----------------

int spanningTree(int V, int E, struct Edge edges[])
{
    // Initialize DSU
    makeSet(V);

    // Sort edges according to weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int mstWt = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < E; i++)
    {
        int wt = edges[i].wt;
        int u = edges[i].u;
        int v = edges[i].v;

        // Check whether adding this edge creates a cycle
        if (findUPar(u) != findUPar(v))
        {
            mstWt += wt;

            unionBySize(u, v);
        }
    }

    return mstWt;
}


// ---------------- MAIN ----------------

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAXE];

    printf("Enter edges as: u v weight\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].wt);
    }

    int mstWt = spanningTree(V, E, edges);

    printf("MST Weight = %d\n", mstWt);

    return 0;
}
