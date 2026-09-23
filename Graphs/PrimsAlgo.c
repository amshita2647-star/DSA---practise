#include <stdio.h>
#define MAX 100
#define INF 9999
void prims(int graph[MAX][MAX], int V)
{
    int visited[MAX] = {0};
    int key[MAX];
    int parent[MAX];
    // Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        parent[i] = -1;
    }
    // Start from vertex 0
    key[0] = 0;
    int total = 0;
    for (int count = 0; count < V; count++)
    {
        // Find minimum key vertex
        int min = INF;
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print MST
    printf("Minimum Spanning Tree:\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d -- %d  weight = %d\n",
               parent[i], i, graph[i][parent[i]]);

        total += graph[i][parent[i]];
    }

    printf("Total weight = %d\n", total);
}

int main()
{
    int V = 5;

    int graph[MAX][MAX] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph, V);

    return 0;
}
