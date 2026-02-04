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
    depth = 0;
    for (i = 0; i < (ssize_t)number_threads; i++) {
        size_t d = current_depth[i] + (i % 3);
        if (d > depth)
            depth = d;
    }
    depth -= (number_threads > 0) ? ((number_threads - 1) % 3) : 0;
}
