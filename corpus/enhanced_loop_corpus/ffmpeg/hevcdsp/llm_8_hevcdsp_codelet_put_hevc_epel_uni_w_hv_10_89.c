#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 6; y++) {
    for (x = 0; x < width; x++) {
        int16_t sum = 0;
        sum += filter[0] * src[x - 2];
        sum += filter[1] * src[x - 1];
        sum += filter[2] * src[x];
        sum += filter[3] * src[x + 1];
        sum += filter[4] * src[x + 2];
        tmp[x] = sum >> (10 - 8);
    }
    src += srcstride;
    tmp += 64;
}
}
