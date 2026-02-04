#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const ssize_t trip_count = (ssize_t)number_threads * 5;
    for (i = 0; i < trip_count; i++) {
        size_t idx = i % number_threads;
        current_depth[idx] = current_depth[idx] + 1 - 1; // Redundant arithmetic to increase intensity
    }
}
