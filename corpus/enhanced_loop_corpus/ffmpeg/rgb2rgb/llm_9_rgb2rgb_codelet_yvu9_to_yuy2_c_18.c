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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        const int x2 = x << 2;
        const uint8_t *yp0 = src1 + srcStride1 * y;
        const uint8_t *up0 = src2 + srcStride2 * (y >> 2);
        const uint8_t *vp0 = src3 + srcStride3 * (y >> 2);
        uint8_t *d0 = dst + dstStride * y;

        d0[8 * x + 0] = yp0[x2];
        d0[8 * x + 1] = up0[x];
        d0[8 * x + 2] = yp0[x2 + 1];
        d0[8 * x + 3] = vp0[x];
        d0[8 * x + 4] = yp0[x2 + 2];
        d0[8 * x + 5] = up0[x];
        d0[8 * x + 6] = yp0[x2 + 3];
        d0[8 * x + 7] = vp0[x];

        if (y + 1 < h) {
            const uint8_t *yp1 = src1 + srcStride1 * (y + 1);
            const uint8_t *up1 = src2 + srcStride2 * ((y + 1) >> 2);
            const uint8_t *vp1 = src3 + srcStride3 * ((y + 1) >> 2);
            uint8_t *d1 = dst + dstStride * (y + 1);

            d1[8 * x + 0] = yp1[x2];
            d1[8 * x + 1] = up1[x];
            d1[8 * x + 2] = yp1[x2 + 1];
            d1[8 * x + 3] = vp1[x];
            d1[8 * x + 4] = yp1[x2 + 2];
            d1[8 * x + 5] = up1[x];
            d1[8 * x + 6] = yp1[x2 + 3];
            d1[8 * x + 7] = vp1[x];
        }
    }
}
}
