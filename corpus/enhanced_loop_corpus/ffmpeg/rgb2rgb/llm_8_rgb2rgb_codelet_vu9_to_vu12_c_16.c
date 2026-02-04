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
for (y = 0; y < h; y++) {
    const uint8_t *s1 = src1 + srcStride1 * (y >> 2);
    uint8_t *d = dst1 + dstStride1 * y;
    for (x = 0; x < w; x += 2) {
        uint8_t val = s1[x >> 1];
        d[4 * x] = d[4 * x + 1] = d[4 * x + 2] = d[4 * x + 3] = val;
        if (x + 1 < w) {
            d[4 * x + 4] = d[4 * x + 5] = d[4 * x + 6] = d[4 * x + 7] = val;
        }
    }
}
}
