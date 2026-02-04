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
    size_t local_depth = depth;
    for (i = 1; i < (ssize_t)number_threads; i += 2) {
        if (i + 1 < (ssize_t)number_threads) {
            size_t val1 = current_depth[i];
            size_t val2 = current_depth[i + 1];
            if (val1 > local_depth)
                local_depth = val1;
            if (val2 > local_depth)
                local_depth = val2;
        } else {
            if (current_depth[i] > local_depth)
                local_depth = current_depth[i];
        }
    }
    depth = local_depth;
}
