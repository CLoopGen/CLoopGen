#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_wrap;
extern  uint8_t *src;
extern int src_wrap;
extern int width;
extern int height;
extern int w;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height -= 2) {
    if (height >= 2) {
        s1 = src;
        s2 = s1 + src_wrap;
        d = dst;
        for (w = width; w >= 4; w -= 4) {
            uint8_t avg1 = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            uint8_t avg2 = (s1[2] + s1[3] + s2[2] + s2[3] + 2) >> 2;
            uint8_t avg3 = (s1[4] + s1[5] + s2[4] + s2[5] + 2) >> 2;
            uint8_t avg4 = (s1[6] + s1[7] + s2[6] + s2[7] + 2) >> 2;
            d[0] = avg1; d[1] = avg2; d[2] = avg3; d[3] = avg4;
            s1 += 8;
            s2 += 8;
            d += 4;
        }
        for (; w > 0; w--) {
            d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            s1 += 2;
            s2 += 2;
            d++;
        }
        src += 2 * src_wrap;
        dst += dst_wrap;

        uint8_t *next_s1 = src;
        uint8_t *next_s2 = next_s1 + src_wrap;
        uint8_t *next_d = dst;
        for (w = width; w >= 4; w -= 4) {
            next_d[0] = (next_s1[0] + next_s1[1] + next_s2[0] + next_s2[1] + 2) >> 2;
            next_d[1] = (next_s1[2] + next_s1[3] + next_s2[2] + next_s2[3] + 2) >> 2;
            next_d[2] = (next_s1[4] + next_s1[5] + next_s2[4] + next_s2[5] + 2) >> 2;
            next_d[3] = (next_s1[6] + next_s1[7] + next_s2[6] + next_s2[7] + 2) >> 2;
            next_s1 += 8;
            next_s2 += 8;
            next_d += 4;
        }
        for (; w > 0; w--) {
            next_d[0] = (next_s1[0] + next_s1[1] + next_s2[0] + next_s2[1] + 2) >> 2;
            next_s1 += 2;
            next_s2 += 2;
            next_d++;
        }
        src += 2 * src_wrap;
        dst += dst_wrap;
    } else {
        s1 = src;
        s2 = s1 + src_wrap;
        d = dst;
        for (w = width; w >= 4; w -= 4) {
            d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            d[1] = (s1[2] + s1[3] + s2[2] + s2[3] + 2) >> 2;
            d[2] = (s1[4] + s1[5] + s2[4] + s2[5] + 2) >> 2;
            d[3] = (s1[6] + s1[7] + s2[6] + s2[7] + 2) >> 2;
            s1 += 8;
            s2 += 8;
            d += 4;
        }
        for (; w > 0; w--) {
            d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
            s1 += 2;
            s2 += 2;
            d++;
        }
        src += 2 * src_wrap;
        dst += dst_wrap;
    }
}
}
