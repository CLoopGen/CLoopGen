#include <stdio.h>

#include <inttypes.h>

extern long *conflicts;
extern int allocno_row_words;
extern long *allocnos_live;
extern int j;
extern int ialloc_prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Simulate indirect addressing via precomputed indices stored in a local array
    long indices[64]; // Assume max size; in practice, this could be dynamic or passed in
    int n = allocno_row_words;
    if (n > 64) n = 64; // Clamp to buffer size for safety

    // Precompute reverse index mapping (same as original order but could be randomized or reordered)
    for (int i = 0; i < n; i++) {
        indices[i] = n - 1 - i; // Reverse order: n-1, n-2, ..., 0
    }

    for (j = 0; j < n; j++) {
        int idx = indices[j]; // Indirect access through index array
        conflicts[ialloc_prod + idx] |= allocnos_live[idx];
    }
}
