#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Forward Access with Local Reordering
    // Instead of scattered accesses around `x + w2`, we precompute an offset to improve spatial locality.
    // This variant restructures memory access to be more cache-friendly by accessing consecutive elements.
    int32_t *base_b = &b[w2];  // Base pointer shifted by w2 to make indexing around w2 more linear
    for (x = 2; x < w2 - 1; x++) {
        int offset = x;
        tmp[offset] = (int)(((unsigned int)(b[offset]) -
            ((int)(9U * base_b[offset - 1] + 9U * base_b[offset] - 
                   base_b[offset + 1] - base_b[offset - 2] + 16) >> 5)));
    }
}
