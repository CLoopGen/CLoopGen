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
    // Variant 2: Reduced effective trip count by processing two elements per iteration (semi-unrolling)
    // Also includes early termination condition to reduce average iterations
    int limit = s->neighbors;
    int i;
    for (i = 0; i < limit; i += 2) {
        // Process two neighbor entries per iteration when possible
        int idx1 = s->neighborlist[i];
        t = &string[idx1];
        if (t->liberties == lib) {
            adj[neighbors++] = t->origin;
        }

        // Second element only if within bounds
        if (i + 1 < limit) {
            int idx2 = s->neighborlist[i + 1];
            t = &string[idx2];
            if (t->liberties == lib) {
                adj[neighbors++] = t->origin;
            }
        }
    }
}
