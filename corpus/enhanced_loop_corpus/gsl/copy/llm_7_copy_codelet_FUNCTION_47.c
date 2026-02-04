#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* buffer = (uint64_t*)malloc(src_size1 * sizeof(uint64_t));
    if (!buffer) return;
    for (i = 0; i < src_size1; i++) {
        buffer[i] = i > 0 ? buffer[i-1] + i : 0;
    }
    // Introduce a read-after-write (RAW) loop-carried dependency: each iteration depends on the previous.
    // This creates a sequential data dependency chain across iterations, preventing parallelization.
    free(buffer);
}
