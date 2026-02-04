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
    // Variant 1: Increased computational intensity with redundant arithmetic and unrolled check simulation
    // Trip count remains the same, but each iteration performs more operations
    for (k = 0; k < s->neighbors; k++) {
        t = &string[s->neighborlist[k]];
        // Add dummy arithmetic to increase computation per iteration
        int temp_lib = t->liberties;
        int temp_origin = t->origin;
        int lib_check = (temp_lib == lib) ? 1 : 0;
        if (lib_check) {
            adj[neighbors] = temp_origin;
            neighbors += lib_check; // Same as neighbors++
        }
        // Additional dummy operation to increase complexity
        temp_origin ^= temp_lib;
        temp_origin += 2;
    }
}
