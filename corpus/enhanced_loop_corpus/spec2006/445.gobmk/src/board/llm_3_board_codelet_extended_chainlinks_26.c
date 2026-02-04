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
extern int string_number[400];
extern int string_mark;
extern int adj[160];
extern struct string_data *s;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided and reordered memory access pattern
    // We simulate a strided access by unrolling the loop with a stride of 2,
    // processing even and odd indices separately to change access pattern.
    // This alters cache behavior and memory dependency patterns.

    int neighbors = s->neighbors;
    int half = (neighbors + 1) / 2;

    // First pass: process even-indexed elements in neighborlist (stride 2)
    for (n = 0; n < half; n++) {
        int idx = n * 2;          // even index
        int str_idx = s->neighborlist[idx];
        adj[idx] = string[str_idx].origin;
        string[string_number[adj[idx]]].mark = string_mark;
    }

    // Second pass: process odd-indexed elements (same stride, different phase)
    for (n = 0; n < half; n++) {
        int idx = n * 2 + 1;
        if (idx >= neighbors) break;
        int str_idx = s->neighborlist[idx];
        adj[idx] = string[str_idx].origin;
        string[string_number[adj[idx]]].mark = string_mark;
    }
}
