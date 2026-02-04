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
for (y = 0; y < h; y++) {
    const uint8_t *s2 = src2 + srcStride2 * (y >> 1);
    uint8_t *d = dst2 + dstStride2 * y;
    for (x = 0; x < w; x++) {
        uint8_t val = s2[x];
        if (val > 0) {
            d[2 * x] = val;
            d[2 * x + 1] = val;
        } else {
            d[2 * x] = 0;
            d[2 * x + 1] = 0;
        }
    }
}
}
