#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 7; y++) {
        int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
        int8_t f4 = filter[4], f5 = filter[5], f6 = filter[6], f7 = filter[7];
        for (x = 0; x < width; x++) {
            uint16_t s_m3 = src[x - 3];
            uint16_t s_m2 = src[x - 2];
            uint16_t s_m1 = src[x - 1];
            uint16_t s_0  = src[x];
            uint16_t s_p1 = src[x + 1];
            uint16_t s_p2 = src[x + 2];
            uint16_t s_p3 = src[x + 3];
            uint16_t s_p4 = src[x + 4];
            tmp[x] = (f0 * s_m3 + f1 * s_m2 + f2 * s_m1 + f3 * s_0 +
                      f4 * s_p1 + f5 * s_p2 + f6 * s_p3 + f7 * s_p4) >> 1;
        }
        src += srcstride;
        tmp += 64;
    }
}
