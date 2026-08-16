#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top1; // Next insertion index for Stack 1 (starts at 0)
    int top2; // Next insertion index for Stack 2 (starts at MAX - 1)
} TwoStacks;

// Initialize stack indices for 0-based indexing
void init(TwoStacks *ts) {
    ts->top1 = 0;
    ts->top2 = MAX - 1;
}

// Push to Stack 1
void push1(TwoStacks *ts, int val) {
    if (ts->top1 > ts->top2) {
        printf("Stack 1 Overflow! Cannot push %d\n", val);
        return;
    }
    ts->arr[ts->top1++] = val; // Store at top1, then post-increment
    printf("Pushed %d to Stack 1\n", val);
}

// Push to Stack 2
void push2(TwoStacks *ts, int val) {
    if (ts->top1 > ts->top2) {
        printf("Stack 2 Overflow! Cannot push %d\n", val);
        return;
    }
    ts->arr[ts->top2--] = val; // Store at top2, then post-decrement
    printf("Pushed %d to Stack 2\n", val);
}

// Pop from Stack 1
int pop1(TwoStacks *ts) {
    if (ts->top1 == 0) { // Empty when top1 reaches 0
        printf("Stack 1 Underflow!\n");
        return -1;
    }
    return ts->arr[--(ts->top1)]; // Pre-decrement top1 to get top element
}

// Pop from Stack 2
int pop2(TwoStacks *ts) {
    if (ts->top2 == MAX - 1) { // Empty when top2 reaches MAX - 1
        printf("Stack 2 Underflow!\n");
        return -1;
    }
    return ts->arr[++(ts->top2)]; // Pre-increment top2 to get top element
}

// Display Stack 1 elements (Top to Bottom)
void display1(TwoStacks ts) {
    if (ts.top1 == 0) {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1 (Top to Bottom): ");
    for (int i = ts.top1 - 1; i >= 0; i--) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");
}

// Display Stack 2 elements (Top to Bottom)
void display2(TwoStacks ts) {
    if (ts.top2 == MAX - 1) {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2 (Top to Bottom): ");
    for (int i = ts.top2 + 1; i < MAX; i++) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");
}

int main() {
    TwoStacks ts;
    init(&ts);

    push1(&ts, 10);
    push1(&ts, 20);
    push1(&ts, 30);

    push2(&ts, 90);
    push2(&ts, 80);

    printf("\n--- Current Stack States ---\n");
    display1(ts);
    display2(ts);

    printf("\n--- Operations ---\n");
    printf("Popped from Stack 1: %d\n", pop1(&ts));
    printf("Popped from Stack 2: %d\n", pop2(&ts));

    printf("\n--- Stack States After Pops ---\n");
    display1(ts);
    display2(ts);

    return 0;
}
