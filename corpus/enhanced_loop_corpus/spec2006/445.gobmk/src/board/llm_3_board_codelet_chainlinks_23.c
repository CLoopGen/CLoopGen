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
extern struct string_data *s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Forward Access with Local Blocking
    // Reorder access to improve spatial locality by grouping operations and using temporary variables.
    // This variant reads neighborlist consecutively and writes adj consecutively but introduces
    // local accumulation via a temporary array to simulate data blocking optimization.
    int temp[160];
    int n = s->neighbors;
    for (k = 0; k < n; k++) {
        temp[k] = s->neighborlist[k];  // stage neighbor indices
    }
    for (k = 0; k < n; k++) {
        adj[k] = string[temp[k]].origin;  // now access string[] using staged indices
    }
}
