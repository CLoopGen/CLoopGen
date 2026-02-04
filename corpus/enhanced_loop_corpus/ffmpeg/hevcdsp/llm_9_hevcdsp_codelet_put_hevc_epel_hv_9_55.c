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
for (y = 0; y < height + 1; y++) {
    for (x = 0; x < width; x++) {
        int16_t val = src[x];
        tmp[x] = ((filter[0] + filter[3]) * val + filter[1] * src[x - 1] + filter[2] * src[x + 1]) >> 1;
    }
    src += srcstride / 2;
    tmp += 32;
}
}
