#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reindexing the array in increasing order
    // The original strided backward traversal is transformed into forward consecutive writes
    long temp[64]; // Local buffer to enable consecutive access pattern
    int start = 100 + 100 - 2;
    int end = 100 - 37;
    int idx = 0;
    for (j = start; j > end; j -= 2) {
        temp[idx++] = ((x[j]) & ((1L << 30) - 2));
    }
    // Write back consecutively to x starting at a fixed offset
    for (int k = 0; k < idx; k++) {
        x[50 + k] = temp[k];
    }
}
