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
    // Variant 2: Consecutive and Localized Memory Access via Local Buffer
    // Pre-load relevant string data into a local contiguous buffer to promote cache locality.
    // Then iterate over the local copy with consecutive memory accesses.

    struct string_data local_neighbors[160];
    int origins[160];

    // Prefetch neighbor data into local arrays for sequential access
    for (k = 0; k < s->neighbors; k++) {
        t = &string[s->neighborlist[k]];
        local_neighbors[k] = *t;
        origins[k] = t->origin;
    }

    // Now process using consecutive memory layout
    for (k = 0; k < s->neighbors; k++) {
        if (local_neighbors[k].liberties == lib)
            adj[neighbors++] = origins[k];
    }
}
