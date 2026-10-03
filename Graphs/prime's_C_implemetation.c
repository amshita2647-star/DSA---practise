#include <stdio.h>
#include <limits.h>

#define MAXV 100
#define MAXE 500
#define MAXHEAP 1000

// Represents one edge in the input graph
struct Edge {
    int u;
    int v;
    int weight;
};

// Represents one entry in the min heap
// {weight, node, parent}
struct HeapNode {
    int weight;
    int node;
    int parent;
};

// Represents an MST edge
struct MSTEdge {
    int parent;
    int node;
    int weight;
};


// ---------------- MIN HEAP FUNCTIONS ----------------

struct HeapNode heap[MAXHEAP];
int heapSize = 0;


// Swap two heap nodes
void swap(struct HeapNode *a, struct HeapNode *b)
{
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}


// Insert into min heap
void push(struct HeapNode value)
{
    int i = heapSize;

    heap[heapSize] = value;
    heapSize++;

    // Move upward
    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent].weight <= heap[i].weight)
            break;

        swap(&heap[parent], &heap[i]);

        i = parent;
    }
}


// Remove minimum element
struct HeapNode pop()
{
    struct HeapNode result = heap[0];

    heapSize--;

    heap[0] = heap[heapSize];

    int i = 0;

    // Move downward
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize &&
            heap[left].weight < heap[smallest].weight)
        {
            smallest = left;
        }

        if (right < heapSize &&
            heap[right].weight < heap[smallest].weight)
        {
            smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);

        i = smallest;
    }

    return result;
}


// ---------------- PRIM'S ALGORITHM ----------------

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
              &edges[i].weight);
    }


    // visited[i] = 1 means vertex i is already in MST
    int visited[MAXV] = {0};


    // Stores MST edges
    struct MSTEdge mst[MAXV];

    int mstCount = 0;

    int sum = 0;


    // Start Prim's algorithm from vertex 0
    struct HeapNode start;

    start.weight = 0;
    start.node = 0;
    start.parent = -1;

    push(start);


    while (heapSize > 0)
    {
        // Get minimum element
        struct HeapNode current = pop();

        int w = current.weight;
        int n = current.node;
        int parent = current.parent;


        // Already included in MST
        if (visited[n] == 1)
        {
            continue;
        }


        // Include node in MST
        visited[n] = 1;

        sum += w;


        // Starting node has no parent
        if (parent != -1)
        {
            mst[mstCount].parent = parent;
            mst[mstCount].node = n;
            mst[mstCount].weight = w;

            mstCount++;
        }


        // Check every edge
        for (int i = 0; i < E; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int weight = edges[i].weight;


            // n -> v
            if (u == n && visited[v] == 0)
            {
                struct HeapNode next;

                next.weight = weight;
                next.node = v;
                next.parent = n;

                push(next);
            }


            // n -> u
            else if (v == n && visited[u] == 0)
            {
                struct HeapNode next;

                next.weight = weight;
                next.node = u;
                next.parent = n;

                push(next);
            }
        }
    }


    // ---------------- OUTPUT ----------------

    printf("\nMST Edges:\n");

    for (int i = 0; i < mstCount; i++)
    {
        printf("%d -- %d  weight = %d\n",
               mst[i].parent,
               mst[i].node,
               mst[i].weight);
    }

    printf("\nTotal MST weight = %d\n", sum);

    return 0;
}
