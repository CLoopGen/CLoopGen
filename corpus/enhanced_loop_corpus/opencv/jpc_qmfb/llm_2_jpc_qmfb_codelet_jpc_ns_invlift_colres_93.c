#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // Instead of incrementing pointers inside the loop, use indexed access with step of 2
    int i;
    for (i = 0; i < numcols; i += 2) {
        if (i + 1 < numcols) {
            // Process two elements at once using consecutive indexing
            hptr2[i] = hptr2[i] + (-(jpc_fix_t)(((
                jpc_fix_big_t)(-1.5861343420599241 * 2. * ((double)(((jpc_fix_t)(1)) << 13)))
                * (jpc_fix_big_t)(lptr2[i])
            ) >> 13));
            hptr2[i + 1] = hptr2[i + 1] + (-(jpc_fix_t)(((
                jpc_fix_big_t)(-1.5861343420599241 * 2. * ((double)(((jpc_fix_t)(1)) << 13)))
                * (jpc_fix_big_t)(lptr2[i + 1])
            ) >> 13));
        } else {
            // Handle odd-sized tail
            hptr2[i] = hptr2[i] + (-(jpc_fix_t)(((
                jpc_fix_big_t)(-1.5861343420599241 * 2. * ((double)(((jpc_fix_t)(1)) << 13)))
                * (jpc_fix_big_t)(lptr2[i])
            ) >> 13));
        }
    }
}
