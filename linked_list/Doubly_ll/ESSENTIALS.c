LLIST insertAt(LLIST l, int data, int atPos, int cuPos) {
    if (l) {
        if (atPos == cuPos) {
            LLIST t = makeNode(data);
            t->next = l;
            l->prev = t; // 1. Link current node back to new node 't'
            return t;
        } else {
            l->next = insertAt(l->next, data, atPos, cuPos + 1);
            if (l->next) {
                l->next->prev = l; // 2. Fix backward link during recursion unwinding
            }
        }
    } 
    // Handle inserting at the end of the list (when l is NULL at atPos)
    else if (atPos == cuPos) {
        return makeNode(data);
    }

    return l;
}
LLIST deleteAt(LLIST l, int atPos, int cuPos) {
    if (l) {
        if (atPos == cuPos) {
            LLIST t = l->next;
            if (t) {
                t->prev = NULL; // If t becomes the new head, set its prev to NULL
            }
            free(l);            // Free memory of deleted node
            return t;           // Return next node to bridge the gap
        } else {
            l->next = deleteAt(l->next, atPos, cuPos + 1);
            if (l->next) {
                l->next->prev = l; // Fix backward link during recursion unwinding
            }
        }
    }
    return l;
}
