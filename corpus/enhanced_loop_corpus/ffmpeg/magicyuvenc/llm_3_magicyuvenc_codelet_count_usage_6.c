#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

extern uint8_t *src;
extern int width;
extern int height;
extern PTable *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an array of indices to access src indirectly, simulating irregular but deterministic access.
    // Since we cannot introduce heap allocation, we assume a static index mapping (e.g., identity with offset).
    // Here, simulate indirect access using precomputed linear indexing without extra storage.
    int total = width * height;
    for (int idx = 0; idx < total; idx++) {
        int pos = idx;  // Identity mapping as base; could be permuted in real use cases
        counts[src[pos]].prob++;
    }
    // Restore final src state as in original: src is advanced by width per row, so after height rows:
    src += width * height;
}
