#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    int index_map[17];
    for (j = 0; j < 16 + 1; j++) {
        index_map[j] = j; // Identity mapping for simplicity, could be randomized or reordered
    }
    for (j = 0; j < 16 + 1; j++) {
        pts_buf[index_map[j]] = (-9223372036854775807L - 1);
    }
}
