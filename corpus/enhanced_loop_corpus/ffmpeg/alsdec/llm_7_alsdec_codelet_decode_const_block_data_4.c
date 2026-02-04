#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int smp;
extern int32_t val;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t local_val = val;
    for (; smp; smp--) {
        dst[smp - 1] = local_val; // Remove pointer arithmetic side effect; eliminate loop-carried dependency via reverse indexing
    }
    // No data dependency between iterations: all writes are to independent memory locations relative to smp
}
