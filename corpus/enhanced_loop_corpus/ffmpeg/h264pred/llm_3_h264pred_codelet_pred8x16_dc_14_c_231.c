#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Access with Fixed Offsets (unroll and reorganize to emphasize strided patterns)
    ptrdiff_t s = stride;
    // Process two iterations at a time with grouped strided access
    for (i = 0; i < 4; i += 2) {
        // Handle two values of i: i and i+1
        dc0 += src[i * s - 1] + src[i - s];
        dc0 += src[(i + 1) * s - 1] + src[i + 1 - s];

        dc1 += src[4 + i - s];
        dc1 += src[4 + i + 1 - s];

        // Accumulate dc2, dc3, dc4 with regular stride-based jumps
        dc2 += src[(i + 4) * s - 1] + src[(i + 5) * s - 1];
        dc3 += src[(i + 8) * s - 1] + src[(i + 9) * s - 1];
        dc4 += src[(i + 12) * s - 1] + src[(i + 13) * s - 1];
    }
}
