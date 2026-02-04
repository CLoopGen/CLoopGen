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
            data[i] += data[i-1]; // RAW (read-after-write) loop-carried dependency: current depends on previous
        }
    }
    // Introduces loop-carried RAW dependency: each iteration reads result of prior iteration.
    // Creates cumulative sum pattern — strong data dependency chain across iterations.
    free(data);
}
