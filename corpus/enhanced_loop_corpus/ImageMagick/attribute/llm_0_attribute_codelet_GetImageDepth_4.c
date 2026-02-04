#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t i = 0; i < (ssize_t)number_threads; i++) {
        current_depth[i] = 1;
        for (size_t j = 0; j < 2; j++) {
            current_depth[i] += j;
        }
    }
}
