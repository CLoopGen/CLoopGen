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
            data[i] += data[i-1]; // Introduce loop-carried RAW (read-after-write) dependency
        }
    }
    free(data);
}
