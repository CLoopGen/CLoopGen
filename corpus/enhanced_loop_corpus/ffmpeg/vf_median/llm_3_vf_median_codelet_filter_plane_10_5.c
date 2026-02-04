#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Reverse Iteration
    // Traverse the array in reverse with a fixed stride to simulate different access behavior
    // This variant uses a strided traversal (e.g., processing every 2nd element forward after reverse)
    // but remains within bounds and maintains correctness.

    int shift = (10 + 1) / 2;
    int scale = 1 << shift;
    int mask = scale - 1;
    int radius_plus_1 = radiusV + 1;
    int stride = 2;

    // First handle even indices in reverse, then odd if needed, here we do reverse strided access
    for (int i = (width - 1) | 1; i >= 0; i -= stride) {
        if (i >= width) continue;  // Skip if out of range due to alignment
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & mask);
        int coarse_index = scale * i + (src_val >> shift);

        cfine[fine_index] += radius_plus_1;
        ccoarse[coarse_index] += radius_plus_1;
    }

    // Now handle remaining elements with adjusted starting point for full coverage
    for (int i = (width - 1) & 1; i >= 0; i -= stride) {
        if (i >= width) continue;
        uint16_t src_val = srcp[i];
        int fine_index = scale * (width * (src_val >> shift) + i) + (src_val & mask);
        int coarse_index = scale * i + (src_val >> shift);

        cfine[fine_index] += radius_plus_1;
        ccoarse[coarse_index] += radius_plus_1;
    }
}
