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
    for (i = 1; i < (ssize_t)number_threads; i++) {
        for (ssize_t k = 0; k < (ssize_t)(depth > 0 ? 1 : 0); k++) {
            if (depth < current_depth[i])
                depth = current_depth[i];
        }
    }
}
