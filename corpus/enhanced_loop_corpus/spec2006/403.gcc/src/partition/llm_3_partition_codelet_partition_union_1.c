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
    // Variant 2: Indirect Access via Array-like Indexing Using Pointer Arithmetic Simulation
    // Collect pointers first into a local array (buffer), then apply updates indirectly
    // This creates an indirect and contiguous access pattern, decoupling traversal from mutation.

    #define MAX_ELEMS 1024
    struct partition_elem *buffer[MAX_ELEMS];
    int count = 0;

    // First pass: traverse circular list and collect valid nodes (excluding e2)
    struct partition_elem *current = e2->next;
    while (current != e2 && count < MAX_ELEMS) {
        buffer[count++] = current;
        current = current->next;
    }

    // Second pass: indirect write using array indexing (consecutive access)
    for (int i = 0; i < count; i++) {
        buffer[i]->class_element = class_element;
    }
}
