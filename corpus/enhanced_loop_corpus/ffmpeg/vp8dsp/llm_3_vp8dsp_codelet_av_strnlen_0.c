#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array (simulated)
    // Since we cannot modify global arrays, simulate indirect pattern using offset calculation
    // Use a virtual "indirect" sequence: access elements in reverse order within chunks of size 8
    size_t chunk_size = 8;
    size_t num_elements = len;
    size_t idx = 0;
    for (i = 0; i < num_elements; i++) {
        // Compute indirect index: reverse index within current chunk
        size_t chunk_idx = i % chunk_size;
        size_t reversed_idx_in_chunk = chunk_size - 1 - chunk_idx;
        size_t effective_idx = (i / chunk_size) * chunk_size + reversed_idx_in_chunk;

        // Bound check
        if (effective_idx >= len) continue;

        // Terminate if null byte is found
        if (!s[effective_idx]) {
            idx = effective_idx;
            break;
        }
        idx = effective_idx;
    }
    // Assign final result to external i
    i = idx;
}
