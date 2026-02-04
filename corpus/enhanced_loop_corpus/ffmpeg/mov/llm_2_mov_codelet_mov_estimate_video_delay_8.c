#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (j = 0; j < 16 + 1; j += 2) {
        pts_buf[j] = (-9223372036854775807L - 1);
    }
    // Fill remaining odd indices in a second pass to maintain correctness
    for (j = 1; j < 16 + 1; j += 2) {
        pts_buf[j] = (-9223372036854775807L - 1);
    }
}
