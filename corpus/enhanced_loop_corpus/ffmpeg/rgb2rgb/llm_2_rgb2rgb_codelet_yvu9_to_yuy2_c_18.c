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
    const uint8_t *yp_base = src1 + srcStride1 * y;
    const uint8_t *up_row = src2 + srcStride2 * (y >> 2);
    const uint8_t *vp_row = src3 + srcStride3 * (y >> 2);
    uint8_t *d = dst + dstStride * y;

    for (x = 0; x < w; x += 4) {
        const int x2_0 = x << 2;
        const int x2_1 = (x+1) << 2;
        const int x2_2 = (x+2) << 2;
        const int x2_3 = (x+3) << 2;

        d[8*x+ 0] = yp_base[x2_0];
        d[8*x+ 1] = up_row[x];
        d[8*x+ 2] = yp_base[x2_0+1];
        d[8*x+ 3] = vp_row[x];
        d[8*x+ 4] = yp_base[x2_0+2];
        d[8*x+ 5] = up_row[x];
        d[8*x+ 6] = yp_base[x2_0+3];
        d[8*x+ 7] = vp_row[x];

        if (x+1 < w) {
            d[8*(x+1)+0] = yp_base[x2_1];
            d[8*(x+1)+1] = up_row[x+1];
            d[8*(x+1)+2] = yp_base[x2_1+1];
            d[8*(x+1)+3] = vp_row[x+1];
            d[8*(x+1)+4] = yp_base[x2_1+2];
            d[8*(x+1)+5] = up_row[x+1];
            d[8*(x+1)+6] = yp_base[x2_1+3];
            d[8*(x+1)+7] = vp_row[x+1];
        }

        if (x+2 < w) {
            d[8*(x+2)+0] = yp_base[x2_2];
            d[8*(x+2)+1] = up_row[x+2];
            d[8*(x+2)+2] = yp_base[x2_2+1];
            d[8*(x+2)+3] = vp_row[x+2];
            d[8*(x+2)+4] = yp_base[x2_2+2];
            d[8*(x+2)+5] = up_row[x+2];
            d[8*(x+2)+6] = yp_base[x2_2+3];
            d[8*(x+2)+7] = vp_row[x+2];
        }

        if (x+3 < w) {
            d[8*(x+3)+0] = yp_base[x2_3];
            d[8*(x+3)+1] = up_row[x+3];
            d[8*(x+3)+2] = yp_base[x2_3+1];
            d[8*(x+3)+3] = vp_row[x+3];
            d[8*(x+3)+4] = yp_base[x2_3+2];
            d[8*(x+3)+5] = up_row[x+3];
            d[8*(x+3)+6] = yp_base[x2_3+3];
            d[8*(x+3)+7] = vp_row[x+3];
        }
    }
}
}
