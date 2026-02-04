#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (ssize_t)number_threads; i++) {
        current_depth[i] = current_depth[i-1] + 1;
    }
    if (number_threads > 0)
        current_depth[0] = 1;
}
