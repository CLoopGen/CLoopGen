#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Modify access pattern to use a larger effective stride (e.g., 2*stride)
    // Simulate a more scattered memory access while preserving loop structure
    for (i = 0; i < 4; i++) {
        ptrdiff_t effective_stride = 2 * stride;
        dc0 += src[i * effective_stride];
        dc1 += src[4 + i * effective_stride];
    }
}
