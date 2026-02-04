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
    // Variant 2: Strided Access with Offset Fusion and Linear Indexing
    // Combine stride and loop index into a unified strided pattern with fused offsets.
    // This version emphasizes regular strided traversal with reduced base+offset recalculations.

    for (i = 0; i < 4; i++) {
        ptrdiff_t idx0 = i * stride;
        ptrdiff_t idx1 = i;

        dc0 += src[-1 + idx0] + src[idx1 - stride];
        dc1 += src[4 + idx1 - stride];
        dc2 += src[-1 + idx0 + 4 * stride];
    }
}
