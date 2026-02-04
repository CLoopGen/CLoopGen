#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t f[2][6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with transformed indexing
    // Change direction and access pattern to process elements from start to end
    // Use offset indexing to maintain dependency chain in forward order
    for (i = 1; i < 6; i++) {
        f[0][i] += (unsigned int)f[0][i - 1];
        f[1][i] -= (unsigned int)f[1][i - 1];
    }
}
