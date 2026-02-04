#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Assume indices are implicitly 0,1,2,... but accessed out of order in groups of 4 (unrolled with indirect pattern)
    int unroll_factor = 4;
    int limit = numcols - (numcols % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        // Access elements in reverse order within each block of 4
        dstptr2[3] = srcptr2[3];
        dstptr2[2] = srcptr2[2];
        dstptr2[1] = srcptr2[1];
        dstptr2[0] = srcptr2[0];
        dstptr2 += unroll_factor;
        srcptr2 += unroll_factor;
    }
    // Handle remaining elements with original sequential access
    for (; i < numcols; ++i) {
        *dstptr2++ = *srcptr2++;
    }
}
