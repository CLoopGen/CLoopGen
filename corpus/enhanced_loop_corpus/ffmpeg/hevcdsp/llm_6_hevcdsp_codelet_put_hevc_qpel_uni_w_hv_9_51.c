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
            uint16_t s0 = src[x - 3], s1 = src[x - 2], s2 = src[x - 1];
            uint16_t s3 = src[x], s4 = src[x + 1], s5 = src[x + 2];
            uint16_t s6 = src[x + 3], s7 = src[x + 4];
            int32_t sum = f0 * s0 + f1 * s1 + f2 * s2 + f3 * s3 +
                          f4 * s4 + f5 * s5 + f6 * s6 + f7 * s7;
            tmp[x] = sum >> 1; // equivalent to >> (9-8)
        }
        src += srcstride;
        tmp += 64;
    }
}
