#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

// -------------------------------------------------------------------
// Circular Queue & Deque Structure Definition
// -------------------------------------------------------------------
typedef struct {
    char val[MAX];
    int front, rear;
} Q;

Q createqueue() {
    Q q;
    q.rear = q.front = 0;
    return q;
}

int isempty(Q q) {
    return (q.front == q.rear);
}

int isfull(Q q) {
    return ((q.rear + 1) % MAX == q.front);
}

// -------------------------------------------------------------------
// Double-Ended Queue (Deque) Operations
// -------------------------------------------------------------------
int insertRear(Q *q, char data) {
    if (isfull(*q)) return 0;
    q->rear = (q->rear + 1) % MAX;
    q->val[q->rear] = data;
    return 1;
}

char deleteFront(Q *q) {
    if (isempty(*q)) return 0;
    q->front = (q->front + 1) % MAX;
    return q->val[q->front];
}

int insertFront(Q *q, char data) {
    if (isfull(*q)) return 0;
    q->val[q->front] = data;
    q->front = (q->front - 1 + MAX) % MAX;
    return 1;
}

char deleteRear(Q *q) {
    if (isempty(*q)) return 0;
    char data = q->val[q->rear];
    q->rear = (q->rear - 1 + MAX) % MAX;
    return data;
}

// -------------------------------------------------------------------
// 1. Size of Queue in terms of front, rear, and MAX
// -------------------------------------------------------------------
int sizeByFormula(Q q) {
    return (q.rear - q.front + MAX) % MAX;
}

// -------------------------------------------------------------------
// 2. Size of Queue by counting elements
// -------------------------------------------------------------------
int sizeByCounting(Q q) {
    int count = 0;
    int i = (q.front + 1) % MAX;
    while (i != (q.rear + 1) % MAX) {
        count++;
        i = (i + 1) % MAX;
    }
    return count;
}

// -------------------------------------------------------------------
// 3. Insert a new value as the i-th element (1-based index)
// -------------------------------------------------------------------
int insertAtIth(Q *q, char data, int pos) {
    int sz = sizeByFormula(*q);
    if (pos < 1 || pos > sz + 1 || isfull(*q)) return 0;

    int curr = q->rear;
    q->rear = (q->rear + 1) % MAX;
    int next = q->rear;

    // Shift elements rightward from rear to make room at pos
    for (int k = sz; k >= pos; k--) {
        q->val[next] = q->val[curr];
        next = curr;
        curr = (curr - 1 + MAX) % MAX;
    }
    q->val[next] = data;
    return 1;
}

// -------------------------------------------------------------------
// 4. Delete the i-th value from the circular queue (1-based index)
// -------------------------------------------------------------------
char deleteIth(Q *q, int pos) {
    int sz = sizeByFormula(*q);
    if (pos < 1 || pos > sz || isempty(*q)) return 0;

    int target_idx = (q->front + pos) % MAX;
    char deleted_val = q->val[target_idx];

    // Shift elements leftward to fill the empty slot
    int curr = target_idx;
    int next = (target_idx + 1) % MAX;
    for (int k = pos; k < sz; k++) {
        q->val[curr] = q->val[next];
        curr = next;
        next = (next + 1) % MAX;
    }
    q->rear = (q->rear - 1 + MAX) % MAX;
    return deleted_val;
}

// -------------------------------------------------------------------
// Stack Helper Structure (For Palindrome Checking)
// -------------------------------------------------------------------
typedef struct {
    char val[MAX];
    int top;
} Stack;

// -------------------------------------------------------------------
// 5. Palindrome Check using Stack and Queue
// -------------------------------------------------------------------
int isPalindrome(char *str) {
    Q q = createqueue();
    Stack s;
    s.top = -1;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        insertRear(&q, str[i]);
        s.val[++s.top] = str[i];
    }

    for (int i = 0; i < len; i++) {
        char q_char = deleteFront(&q);
        char s_char = s.val[s.top--];
        if (q_char != s_char) return 0;
    }
    return 1;
}

// -------------------------------------------------------------------
// 6. Check if string is of form "w.w" where w is a string of letters
// -------------------------------------------------------------------
int isFormWdotW(char *str) {
    Q q = createqueue();
    int i = 0;

    // Enqueue string 'w' until '.'
    while (str[i] != '\0' && str[i] != '.') {
        insertRear(&q, str[i]);
        i++;
    }

    // Must encounter '.' separator
    if (str[i] != '.') return 0;
    i++; // Skip '.'

    // Match second 'w' against queue
    while (str[i] != '\0') {
        if (isempty(q)) return 0;
        if (deleteFront(&q) != str[i]) return 0;
        i++;
    }

    return isempty(q);
}

// -------------------------------------------------------------------
// Main Demonstration
// -------------------------------------------------------------------
int main() {
    Q q = createqueue();

    // Demonstrate Deque & Size
    insertRear(&q, 'A');
    insertRear(&q, 'B');
    insertRear(&q, 'C');
    printf("Size by Formula: %d\n", sizeByFormula(q));
    printf("Size by Counting: %d\n", sizeByCounting(q));

    // Demonstrate i-th insertion & deletion
    insertAtIth(&q, 'X', 2); // Insert 'X' at position 2 -> A, X, B, C
    printf("Deleted 2nd Element: %c\n", deleteIth(&q, 2)); // Deletes 'X'

    // Demonstrate Palindrome
    char pal[] = "radar";
    printf("Is '%s' Palindrome? %s\n", pal, isPalindrome(pal) ? "Yes" : "No");

    // Demonstrate w.w check
    char w_str[] = "cat.cat";
    printf("Is '%s' of form w.w? %s\n", w_str, isFormWdotW(w_str) ? "Yes" : "No");

    return 0;
}
