#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (access every other pair)
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1);
    // Access elements with stride of 2 in the logical index space
    for (i = start; i < end; i += 2) {
        if (i + 1 < end) {  // Ensure we don't go out of bounds
            // Operate on two spaced indices simultaneously to increase stride effect
            int idx_lo = 2 * i;
            int idx_hi = 2 * (i + 1);
            p[idx_lo + 1] += (57862LL * (p[idx_lo] + p[idx_lo + 2]) + (1 << 15)) >> 16;
            p[idx_hi + 1] += (57862LL * (p[idx_hi] + p[idx_hi + 2]) + (1 << 15)) >> 16;
        } else {
            // Handle odd-sized range tail
            int idx = 2 * i;
            p[idx + 1] += (57862LL * (p[idx] + p[idx + 2]) + (1 << 15)) >> 16;
        }
    }
}
