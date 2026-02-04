#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int dx;
extern int dy;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern  uint8_t *src4;
extern int stride1;
extern int stride2;
extern int stride3;
extern int stride4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < b_h; y += 2) {
        for (x = 0; x < b_w; x += 2) {
            int val1 = src1[x];
            int val2 = src2[x];
            int val3 = src3[x];
            int val4 = src4[x];
            int temp = ((8 - dx) * (8 - dy) * val1 + dx * (8 - dy) * val2 +
                       (8 - dx) * dy * val3 + dx * dy * val4 + 32) >> 6;
            dst[x] = (uint8_t)temp;

            if (x + 1 < b_w) {
                val1 = src1[x + 1]; val2 = src2[x + 1];
                val3 = src3[x + 1]; val4 = src4[x + 1];
                temp = ((8 - dx) * (8 - dy) * val1 + dx * (8 - dy) * val2 +
                       (8 - dx) * dy * val3 + dx * dy * val4 + 32) >> 6;
                dst[x + 1] = (uint8_t)temp;
            }
        }
        src1 += stride1;
        src2 += stride2;
        src3 += stride3;
        src4 += stride4;
        dst += stride;

        if (y + 1 < b_h) {
            for (x = 0; x < b_w; x++) {
                dst[stride + x] = ((8 - dx) * (8 - dy) * src1[stride1 + x] +
                                   dx * (8 - dy) * src2[stride2 + x] +
                                   (8 - dx) * dy * src3[stride3 + x] +
                                   dx * dy * src4[stride4 + x] + 32) >> 6;
            }
            dst += stride;
        }
    }
}
