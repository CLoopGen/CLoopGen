#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_accum[4] = {0}; // Local array to remove loop-carried dependencies
    for (; ii < (224 + (8 * 8) - 1) / (8 * 8); ii++) {
        local_accum[ii % 4] += ii;        // Break dependency on c_d; use local state with modulo indexing
        c_d[ii] = local_accum[ii % 4];    // Write independent of prior c_d values — no loop-carried dependency
    }
}
