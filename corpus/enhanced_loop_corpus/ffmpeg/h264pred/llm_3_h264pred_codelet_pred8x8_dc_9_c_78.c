#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using precomputed index array
    // Simulate indirect access via an index buffer to demonstrate irregular pattern handling
    int indices[8];
    for (int j = 0; j < 4; j++) {
        indices[j]     = -1 + j * stride;           // for dc0 first term
        indices[j+4]   = -1 + (j + 4) * stride;     // for dc2
    }
    // Additional indices for other terms
    int idx_temp[4];
    for (int j = 0; j < 4; j++) {
        idx_temp[j] = j - stride;                  // for dc0 second term
    }

    for (int j = 0; j < 4; j++) {
        dc0 += src[indices[j]] + src[idx_temp[j]];
        dc1 += src[4 + j - stride];                // kept as-is but could be indexed indirectly too
        dc2 += src[indices[j+4]];
    }
}
