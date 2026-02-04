#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w - 7; x += 8) {
        int skip = (src[2 * x + 1] & 1);  // Sample a bit from source to conditionally skip update
        if (!skip) {
            dst[x + 0] = src[2 * x + 0];
            dst[x + 1] = src[2 * x + 2];
            dst[x + 2] = src[2 * x + 4];
            dst[x + 3] = src[2 * x + 6];
            dst[x + 4] = src[2 * x + 8];
            dst[x + 5] = src[2 * x + 10];
            dst[x + 6] = src[2 * x + 12];
            dst[x + 7] = src[2 * x + 14];
        } else {
            // Skip writing this block, but maintain forward progress
            continue;
        }
    }
}
