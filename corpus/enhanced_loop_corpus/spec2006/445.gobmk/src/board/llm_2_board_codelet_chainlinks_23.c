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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing adj[] sequentially, write with a stride of 2 (simulating non-unit stride).
    // Fill even indices first, then handle odd if needed (here we assume neighbors is even for simplicity).
    int n = s->neighbors;
    int j = 0;
    // First pass: write to even indices
    for (k = 0; k < n; k++) {
        adj[j] = string[s->neighborlist[k]].origin;
        j += 2;
        if (j >= 160) break; // prevent overflow
    }
}
