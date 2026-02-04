#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increasing stride pattern
    ssize_t step = 2;
    for (i = 1; i < (ssize_t)number_threads; i += step) {
        if (i < (ssize_t)number_threads && depth < current_depth[i])
            depth = current_depth[i];
        step = (step == 2) ? 3 : 2; // Alternate between stride 2 and 3
    }
    // Final pass for any skipped indices due to striding
    for (i = 2; i < (ssize_t)number_threads; i++) {
        if (depth < current_depth[i])
            depth = current_depth[i];
    }
}
