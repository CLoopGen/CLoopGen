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
    const uint8_t *up = src2 + srcStride2 * (y >> 2);
    const uint8_t *vp = src3 + srcStride3 * (y >> 2);
    uint8_t *d = dst + dstStride * y;
    for (x = 0; x < w; x++) {
        const int x2 = x << 2;
        uint8_t temp_yp0 = yp[x2];
        uint8_t temp_yp1 = yp[x2 + 1];
        uint8_t temp_yp2 = yp[x2 + 2];
        uint8_t temp_yp3 = yp[x2 + 3];
        uint8_t temp_up = up[x];
        uint8_t temp_vp = vp[x];
        d[8 * x + 0] = temp_yp0;
        d[8 * x + 1] = temp_up;
        d[8 * x + 2] = temp_yp1;
        d[8 * x + 3] = temp_vp;
        d[8 * x + 4] = temp_yp2;
        d[8 * x + 5] = temp_up;
        d[8 * x + 6] = temp_yp3;
        d[8 * x + 7] = temp_vp;
    }
}
}
