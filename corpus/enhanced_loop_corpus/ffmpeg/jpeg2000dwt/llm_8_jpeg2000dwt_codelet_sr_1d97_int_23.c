#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and additional arithmetic
    // Trip count reduced by factor of 2 via step increment, but more computations per iteration
    for (i = (i0 >> 1); i < (i1 >> 1); i += 2) {
        if (i + 1 < (i1 >> 1)) {
            // Unroll two iterations and expand computation with extra terms
            int64_t t1 = (int64_t)p[2*i] + p[2*i + 2];
            int64_t t2 = (int64_t)p[2*i + 2] + p[2*i + 4];
            p[2*i + 1] += (103949LL * t1 + 78457LL * t2 + (1 << 15)) >> 16;
            p[2*i + 3] += (103949LL * t2 + 78457LL * ((int64_t)p[2*(i+1)] + p[2*(i+1)+2]) + (1 << 15)) >> 16;
        } else {
            // Handle remaining element
            p[2*i + 1] += (103949LL * ((int64_t)p[2*i] + p[2*i + 2]) + (1 << 15)) >> 16;
        }
    }
}
