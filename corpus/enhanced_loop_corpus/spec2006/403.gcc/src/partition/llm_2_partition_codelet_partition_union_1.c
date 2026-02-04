#include <stdio.h>

#include <inttypes.h>

struct partition_elem {
    int class_element;
    struct partition_elem *next;
    unsigned int class_count;
};


extern struct partition_elem *e2;
extern struct partition_elem *p;
extern int class_element;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Simulate strided access by skipping every other node in the linked list traversal.
    // This changes the memory access pattern to non-consecutive, accessing every 2nd element.

    if (e2 == NULL || e2->next == NULL) return;

    struct partition_elem *start = e2->next;
    struct partition_elem *p = start;

    for (; p != e2; ) {
        p->class_element = class_element;
        // Stride: skip next element if exists and not pointing back to e2
        if (p->next != e2 && p->next != NULL) {
            p = p->next->next;
        } else {
            break;
        }
        // Handle case where p becomes null due to double step
        if (p == NULL) break;
    }
}
