#include <stdio.h>

#include <inttypes.h>

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern struct string_data string[240];
extern int adj[160];
extern int lib;
extern struct string_data *s;
extern struct string_data *t;
extern int k;
extern int neighbors;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (Pointer-based) Memory Access Pattern
    // Replace array indexing with pointer arithmetic to simulate indirect traversal.
    // We traverse neighborlist using a pointer and compute t accordingly.
    int *neighbor_ptr = s->neighborlist;
    int *end_ptr = neighbor_ptr + s->neighbors;

    neighbors = 0; // Reset neighbors counter

    for (k = 0; neighbor_ptr < end_ptr; k++, neighbor_ptr++) {
        t = &string[*neighbor_ptr];
        if (t->liberties <= lib)
            adj[neighbors++] = t->origin;
    }
}
