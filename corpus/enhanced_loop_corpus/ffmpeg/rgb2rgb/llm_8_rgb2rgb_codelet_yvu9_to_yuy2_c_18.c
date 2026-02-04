#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern uint8_t *dst;
extern int srcStride1;
extern int srcStride2;
extern int srcStride3;
extern int dstStride;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    const uint8_t *yp = src1 + srcStride1 * y;
    const uint8_t *up = src2 + srcStride2 * (y >> 1);
    const uint8_t *vp = src3 + srcStride3 * (y >> 1);
    uint8_t *d = dst + dstStride * y;
    for (x = 0; x < w; x += 2) {
        const int x2 = x << 2;
        d[8 * x + 0] = yp[x2];
        d[8 * x + 1] = up[x >> 1];
        d[8 * x + 2] = yp[x2 + 1];
        d[8 * x + 3] = vp[x >> 1];
        d[8 * x + 4] = yp[x2 + 2];
        d[8 * x + 5] = up[x >> 1];
        d[8 * x + 6] = yp[x2 + 3];
        d[8 * x + 7] = vp[x >> 1];

        if (x + 1 < w) {
            const int x2_next = (x + 1) << 2;
            d[8 * (x + 1) + 0] = yp[x2_next];
            d[8 * (x + 1) + 1] = up[(x + 1) >> 1];
            d[8 * (x + 1) + 2] = yp[x2_next + 1];
            d[8 * (x + 1) + 3] = vp[(x + 1) >> 1];
            d[8 * (x + 1) + 4] = yp[x2_next + 2];
            d[8 * (x + 1) + 5] = up[(x + 1) >> 1];
            d[8 * (x + 1) + 6] = yp[x2_next + 3];
            d[8 * (x + 1) + 7] = vp[(x + 1) >> 1];
        }
    }
}
}
