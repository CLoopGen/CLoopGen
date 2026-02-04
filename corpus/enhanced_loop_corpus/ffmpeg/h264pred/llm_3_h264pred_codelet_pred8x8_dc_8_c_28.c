#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index array
    // Use precomputed indices to simulate irregular/indirect access pattern
    ptrdiff_t indices0[8], indices1[4], indices2[4];
    
    // Precompute all required memory offsets
    for (int j = 0; j < 4; j++) {
        indices0[2*j]     = -1 + j * stride;        // src[-1 + j * stride]
        indices0[2*j+1]   = j - stride;             // src[j - stride]
        indices1[j]       = 4 + j - stride;
        indices2[j]       = -1 + (j + 4) * stride;
    }

    for (i = 0; i < 4; i++) {
        dc0 += src[indices0[2*i]] + src[indices0[2*i+1]];
        dc1 += src[indices1[i]];
        dc2 += src[indices2[i]];
    }
}
