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



void loop(){
    // Variant 2: Reduced effective trip count and simplified condition with direct indexing
    // Simulates lower computational load by skipping elements and reducing memory accesses
    int step = 2;  // Process every second neighbor, reducing effective iterations
    int limit = s->neighbors;

    for (k = 0; k < limit; k += step) {
        t = &string[s->neighborlist[k]];
        // Skip full structure access when possible
        if ((t->liberties - lib) <= 0) {
            adj[neighbors] = t->origin;
            neighbors++;
        }
    }

    // Handle remaining element if neighbors count is odd
    if (s->neighbors > 0 && (s->neighbors % 2) == 1) {
        k = s->neighbors - 1;
        t = &string[s->neighborlist[k]];
        if (t->liberties <= lib) {
            adj[neighbors++] = t->origin;
        }
    }
}
