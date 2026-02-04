#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating pattern across rows
    uint32_t *row_start;
    for (i = 0; i < 8; i++) {
        row_start = (uint32_t *)(src + i * stride);
        // Write to non-consecutive elements in the same row (strided within row)
        row_start[0] = dc0;
        row_start[2] = dc0;  // Changed index from 1 to 2 for strided access
    }
}
