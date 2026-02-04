#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of incrementing lptr2 and hptr2 separately per iteration,
    // precompute base indices and access elements consecutively in a blocked manner.
    // This improves spatial locality and enables better vectorization.

    jpc_fix_t *lbase = lptr2;
    jpc_fix_t *hbase = hptr2;

    for (i = 0; i < 16; ++i) {
        int idx = i;
        lbase[idx] -= (hbase[idx] + hbase[idx + stride] + 2) >> 2;
    }

    // Update the external pointers to reflect advancement
    lptr2 += 16;
    hptr2 += 16;
}
