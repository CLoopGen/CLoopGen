#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (coalesced) memory access via temporary accumulation
    // Instead of indirect access nmem[c[i]], accumulate updates in a local array
    // assuming that values in c[i] are within a limited range [0..MAX_TEMP_BUF-1]
    // This changes access pattern to be more predictable and consecutive.

    #define MAX_TEMP_BUF 256
    static int temp_count[MAX_TEMP_BUF] = {0}; // Local histogram buffer
    int val;

    // First pass: count frequency of indices using direct indexing
    for (i = 0; i < nseq; i++) {
        val = c[i];
        if (val >= 0 && val < MAX_TEMP_BUF) {
            temp_count[val]++;
        }
    }

    // Second pass: apply accumulated increments consecutively
    for (i = 0; i < MAX_TEMP_BUF; i++) {
        if (temp_count[i] != 0) {
            nmem[i] += temp_count[i];
        }
    }

    #undef MAX_TEMP_BUF
}
