#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 7; y++) {
        int8_t f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
        int8_t f4 = filter[4], f5 = filter[5], f6 = filter[6], f7 = filter[7];
        for (x = 0; x < width; x++) {
            int16_t sum = 0;
            sum += f0 * src[x - 3];
            sum += f1 * src[x - 2];
            sum += f2 * src[x - 1];
            sum += f3 * src[x];
            sum += f4 * src[x + 1];
            sum += f5 * src[x + 2];
            sum += f6 * src[x + 3];
            sum += f7 * src[x + 4];
            tmp[x] = sum >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
