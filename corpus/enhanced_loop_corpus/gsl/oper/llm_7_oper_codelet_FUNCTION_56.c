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
            data[i] += data[i-1]; // Loop-carried RAW dependency: each iteration depends on previous result
        }
    }
    free(data);
    // Creates loop-carried dependency (RAW) across iterations, transforming the loop into a prefix-like sum.
}
