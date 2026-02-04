#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t index = 0;
    size_t total_size = size1 * size2;
    for (i = 0; i < total_size; i++) {
        // Consecutive linear traversal: simulate flat array access
        // Maps 1D index to 2D logic if needed, enables better prefetching
        index = i;
    }
}
