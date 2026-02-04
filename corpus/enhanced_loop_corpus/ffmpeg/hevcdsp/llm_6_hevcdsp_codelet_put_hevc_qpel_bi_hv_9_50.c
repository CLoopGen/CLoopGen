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
        uint16_t *s = src;
        for (x = 0; x < width; x++) {
            int16_t sum = f0 * s[x - 3] +
                          f1 * s[x - 2] +
                          f2 * s[x - 1] +
                          f3 * s[x] +
                          f4 * s[x + 1] +
                          f5 * s[x + 2] +
                          f6 * s[x + 3] +
                          f7 * s[x + 4];
            tmp[x] = sum >> 1; // equivalent to >> (9-8)
        }
        src += srcstride;
        tmp += 64;
    }
}
