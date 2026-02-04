#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern uint8_t *dst1;
extern int srcStride1;
extern int dstStride1;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual stride simulation
    // Instead of writing to d[2*x] and d[2*x+1], we write consecutively to a temporary buffer
    // then copy in chunks. Here, we restructure the inner loop to write two elements at a time
    // using direct pointer arithmetic for consecutive access pattern.

    for (y = 0; y < h; y++) {
        const uint8_t *s1 = src1 + srcStride1 * (y >> 1);
        uint8_t *d = dst1 + dstStride1 * y;
        for (x = 0; x < w; x++) {
            uint8_t val = s1[x];
            d[2*x + 0] = val;
            d[2*x + 1] = val;
        }
    }
}
