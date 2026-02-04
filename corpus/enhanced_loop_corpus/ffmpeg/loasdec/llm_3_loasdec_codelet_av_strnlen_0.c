#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated stride)
    // Use a fixed small lookup table for indirect access pattern (e.g., access every other char in shuffled order)
    size_t stride_map[] = {0, 2, 1, 3}; // Example small pattern for indirect indexing
    size_t map_size = 4;
    size_t j = 0;
    for (i = 0; i < len; ) {
        size_t idx = i + stride_map[j % map_size];
        if (idx >= len || !s[idx]) {
            i = idx;
            break;
        }
        i++;
        j++;
    }
    // Finalize i to point to the actual first null or limit
    for (; i < len && s[i]; i++)
        ;
}
