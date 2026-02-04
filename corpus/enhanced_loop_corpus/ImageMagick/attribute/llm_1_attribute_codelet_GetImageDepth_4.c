#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (ssize_t)number_threads; outer++) {
        for (ssize_t inner = 0; inner < 1; inner++) {
            current_depth[outer] = 1;
        }
    }
}
