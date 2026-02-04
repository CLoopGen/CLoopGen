#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src2;
extern uint8_t *dst2;
extern int srcStride2;
extern int dstStride2;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    const uint8_t *s2_row0 = src2 + srcStride2 * (y >> 1);
    const uint8_t *s2_row1 = (y + 1 < h) ? src2 + srcStride2 * ((y + 1) >> 1) : s2_row0;
    uint8_t *d0 = dst2 + dstStride2 * y;
    uint8_t *d1 = (y + 1 < h) ? dst2 + dstStride2 * (y + 1) : d0;
    for (x = 0; x < w; x++) {
        d0[2 * x] = d0[2 * x + 1] = s2_row0[x];
        if (y + 1 < h) {
            d1[2 * x] = d1[2 * x + 1] = s2_row1[x];
        }
    }
}
}
