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
    // Variant 2: Strided Memory Access with increased stride (simulating cache behavior change)
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 1;
    ptrdiff_t stride = 4;  // Use larger stride for scattered access pattern
    for (i = start; i < end; i++) {
        ptrdiff_t idx_mid = 2 * i;
        ptrdiff_t idx_prev = (idx_mid - stride >= 0) ? idx_mid - stride : 0;
        ptrdiff_t idx_next = idx_mid + stride;
        // Use strided neighbors instead of immediate neighbors
        p[2 * i + 1] -= (103949LL * (p[idx_prev] + p[idx_next]) + (1 << 15)) >> 16;
    }
}
