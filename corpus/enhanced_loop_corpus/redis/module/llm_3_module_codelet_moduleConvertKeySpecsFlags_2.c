#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t flags;
extern int64_t out;
extern int64_t map[][2];
extern int from_idx;
extern int to_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access via pointer arithmetic
    // Uses a pointer to traverse the map array, simulating indirect access pattern
    int64_t (*ptr)[2] = &map[0];
    for (; (*ptr)[0]; ptr++) {
        if (flags & (*ptr)[from_idx])
            out |= (*ptr)[to_idx];
    }
}
