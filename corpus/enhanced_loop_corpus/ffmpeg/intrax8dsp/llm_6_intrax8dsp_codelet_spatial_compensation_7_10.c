#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    uint8_t temp[8];
    for (x = 0; x < 8; x++) {
        if (x - 2 * y > 0) {
            int idx1 = (8 + 8) - 1 + x - 2 * y;
            int idx2 = (8 + 8) + x - 2 * y;
            temp[x] = (src[idx1] + src[idx2] + 1) >> 1;
        } else {
            temp[x] = src[(8) + 8 - y + (x >> 1)];
        }
    }
    for (x = 0; x < 8; x++) {
        dst[x] = temp[x];
    }
    dst += stride;
}
}
