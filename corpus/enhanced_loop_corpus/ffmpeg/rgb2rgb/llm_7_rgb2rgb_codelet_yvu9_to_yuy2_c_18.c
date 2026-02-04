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
    uint8_t prev_up = 0, prev_vp = 0;
    for (x = 0; x < w; x++) {
        const int x2 = x << 2;
        uint8_t curr_up = up[x];
        uint8_t curr_vp = vp[x];
        d[8 * x + 0] = yp[x2];
        d[8 * x + 1] = (x == 0) ? curr_up : prev_up; // Introduce WAR-like dependency: use previous iteration's value
        d[8 * x + 2] = yp[x2 + 1];
        d[8 * x + 3] = (x == 0) ? curr_vp : prev_vp;
        d[8 * x + 4] = yp[x2 + 2];
        d[8 * x + 5] = curr_up;
        d[8 * x + 6] = yp[x2 + 3];
        d[8 * x + 7] = curr_vp;
        prev_up = curr_up; // Create loop-carried WAW dependency
        prev_vp = curr_vp;
    }
}
}
