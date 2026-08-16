#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *val;      // Dynamic array holding stack elements
    int top;       // Index of top element (-1 when empty)
    int capacity;  // Current maximum size (MAX)
} STACK;

// Initialize stack with an initial capacity
STACK createStack(int initial_capacity) {
    STACK s;
    s.capacity = initial_capacity;
    s.top = -1;
    s.val = (int *)malloc(s.capacity * sizeof(int));
    if (s.val == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return s;
}

// Push operation with dynamic doubling
void push(STACK *s, int element) {
    // Check if stack is full
    if (s->top == s->capacity - 1) {
        int new_capacity = s->capacity * 2;
        int *temp = (int *)realloc(s->val, new_capacity * sizeof(int));
        
        if (temp == NULL) {
            printf("Reallocation failed! Stack Overflow.\n");
            return;
        }
        
        s->val = temp;
        s->capacity = new_capacity;
        printf("\n[Stack Full] Capacity doubled from %d to %d\n", s->capacity / 2, s->capacity);
    }
    
    s->val[++(s->top)] = element;
}

int pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->val[(s->top)--];
}

void freeStack(STACK *s) {
    free(s->val);
    s->val = NULL;
    s->top = -1;
    s->capacity = 0;
}

int main() {
    // Start with a small MAX size of 2 to demonstrate doubling
    STACK s = createStack(2);

    push(&s, 10);
    push(&s, 20);
    
    // This push triggers doubling capacity to 4
    push(&s, 30); 
    push(&s, 40);
    
    // This push triggers doubling capacity to 8
    push(&s, 50);

    printf("\nCurrent Stack Elements (Top to Bottom):\n");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.val[i]);
    }
    printf("\nFinal Capacity: %d\n", s.capacity);

    freeStack(&s);
    return 0;
}
