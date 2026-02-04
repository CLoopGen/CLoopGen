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
    // Variant 1: Consecutive Memory Access (reorder computation to access memory consecutively)
    ptrdiff_t s = stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[i * s - 1] + src[i - s];
        dc1 += src[i - s + 4];
        // Group vertical accesses into a temporary sequential pattern using local offsets
        int idx2 = (i + 4) * s - 1;
        int idx3 = (i + 8) * s - 1;
        int idx4 = (i + 12) * s - 1;
        dc2 += src[idx2];
        dc3 += src[idx3];
        dc4 += src[idx4];
    }
}
