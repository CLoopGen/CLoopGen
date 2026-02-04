#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *data = (uint64_t*)malloc(loop_lim * sizeof(uint64_t));
    if (!data) return;
    for (i = 0; i < loop_lim; i++) {
        data[i] = i;
        if (i > 0) {
            data[i] += data[i-1]; // Introduce RAW (read-after-write) loop-carried dependency
        }
    }
    // This version has a true dependence (RAW) carried across loop iterations: each element depends on the previous.
    // Creates cumulative sum pattern with strong loop-carried dependency.
    free(data);
}
