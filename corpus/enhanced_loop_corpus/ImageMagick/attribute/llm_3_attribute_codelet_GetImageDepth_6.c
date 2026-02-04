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
    size_t *indices[] = {&current_depth[1], &current_depth[3], &current_depth[0], &current_depth[2]};
    size_t num_accesses = 4;
    for (i = 0; i < (ssize_t)num_accesses && (i+1) < (ssize_t)number_threads; i++) {
        size_t idx = (i+1) % number_threads ? (i+1) : 1;
        if (depth < *indices[idx % 4])
            depth = *indices[idx % 4];
    }
    // Fallback: sequential scan from last point if needed
    for (i = 5; i < (ssize_t)number_threads; i++)
        if (depth < current_depth[i])
            depth = current_depth[i];
}
