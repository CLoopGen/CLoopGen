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
    int factor = (dx * dy + 32) >> 6;
    if (factor == 0) factor = 1;

    for (y = 0; y < b_h; y++) {
        uint8_t *d = dst;
        uint8_t *s1 = src1;
        uint8_t *s2 = src2;
        uint8_t *s3 = src3;
        uint8_t *s4 = src4;

        for (x = 0; x < b_w; x += 4) {
            int limit = (x + 4 <= b_w) ? x + 4 : b_w;
            for (; x < limit; x++) {
                int weighted = (src1[x] + src2[x] + src3[x] + src4[x]) / 4;
                d[x] = (uint8_t)((weighted * factor) & 0xFF);
            }
        }

        src1 += stride1;
        src2 += stride2;
        src3 += stride3;
        src4 += stride4;
        dst += stride;
    }
}
