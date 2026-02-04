#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[64];
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int sum = 0;
            sum += filter[0] * src[x - 3];
            sum += filter[1] * src[x - 2];
            sum += filter[2] * src[x - 1];
            sum += filter[3] * src[x];
            sum += filter[4] * src[x + 1];
            sum += filter[5] * src[x + 2];
            sum += filter[6] * src[x + 3];
            sum += filter[7] * src[x + 4];
            temp[x] = sum >> 8;
        }
        for (x = 0; x < width; x++) {
            dst[x] = temp[x];
        }
        src += srcstride;
        dst += 64;
    }
}
