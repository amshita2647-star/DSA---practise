
#include <stdio.h>

#define MAX 100

struct Element
{
    int data;
    int priority;
};

struct Element heap[MAX];
int size = 0;

// Swap two elements
void swap(struct Element *a, struct Element *b)
{
    struct Element temp = *a;
    *a = *b;
    *b = temp;
}

// INSERT operation
void insert(int data, int priority)
{
    if(size == MAX - 1)
    {
        printf("Priority Queue is Full\n");
        return;
    }

    size++;

    int i = size;

    heap[i].data = data;
    heap[i].priority = priority;

    // Heapify Up
    while(i > 1 && heap[i].priority < heap[i/2].priority)
    {
        swap(&heap[i], &heap[i/2]);
        i = i/2;
    }

    printf("Element inserted successfully\n");
}

// DELETE operation
void deleteMin()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d (Priority: %d)\n",
           heap[1].data, heap[1].priority);

    // Replace root with last element
    heap[1] = heap[size];
    size--;

    // Heapify Down
    int i = 1;

    while(2*i <= size)
    {
        int smallest = 2*i;

        // Check right child
        if(2*i+1 <= size &&
           heap[2*i+1].priority < heap[smallest].priority)
        {
            smallest = 2*i+1;
        }

        // Check parent and smallest child
        if(heap[i].priority <= heap[smallest].priority)
            break;

        swap(&heap[i], &heap[smallest]);

        i = smallest;
    }
}

// DISPLAY operation
void display()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("\nData\tPriority\n");

    for(int i = 1; i <= size; i++)
    {
        printf("%d\t%d\n", heap[i].data,
                           heap[i].priority);
    }
}

// MAIN FUNCTION
int main()
{
    insert(10, 4);
    insert(20, 2);
    insert(30, 5);
    insert(40, 1);
    insert(50, 3);

    printf("\nPriority Queue after insertion:");
    display();

    deleteMin();

    printf("\nPriority Queue after deletion:");
    display();

    return 0;
}
